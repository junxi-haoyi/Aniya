#pragma once
#if 1
#include <esp_log.h>
#include <lvgl/lvgl.h>
#include "../disp/hal_disp.hpp"
#include "../tp/hal_lcd_tp.hpp"
#include "../tp/hal_tp.hpp"
#include "lv_demos.h"
#include "hal.hpp"

namespace LVGL
{
    static const char *TAG = "LVGL";

    static lgfx::LGFX_Device *_disp;
    static FT3168::TP_FT3168 *_tp;
    static FT3168::TouchPoint_t _tpp;

    class LVGL
    {
    private:
        static void _disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
        {
            uint32_t w = (area->x2 - area->x1 + 1);
            uint32_t h = (area->y2 - area->y1 + 1);

            _disp->startWrite();
            _disp->setWindow(area->x1, area->y1, area->x2, area->y2);
            _disp->writePixels(&color_p->full, w * h, true);
            _disp->endWrite();

            lv_disp_flush_ready(disp_drv);
        }

        /*Will be called by the library to read the touchpad*/
        static void _touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
        {
            _tp->getTouchRaw(_tpp);
            if (_tpp.x != -1)
            {
                // printf("%d %d\n", tpp.x, tpp.y);
                data->point.x = _tpp.x;
                data->point.y = _tpp.y;
                data->state = LV_INDEV_STATE_PRESSED;
            }
            else
            {
                data->state = LV_INDEV_STATE_RELEASED;
            }
        }

        inline void _lv_port_disp_init()
        {
            static lv_disp_draw_buf_t draw_buf_dsc_3;
            lv_color_t *buf_3_1 = (lv_color_t *)heap_caps_malloc(_disp->width() * _disp->height() * sizeof(lv_color_t *), MALLOC_CAP_SPIRAM);
            lv_color_t *buf_3_2 = (lv_color_t *)heap_caps_malloc(_disp->width() * _disp->height() * sizeof(lv_color_t *), MALLOC_CAP_SPIRAM);

            // if((buf_3_1 == NULL) || (buf_3_2 == NULL))
            // {
            //     ESP_LOGE(TAG, "malloc buffer from PSRAM failed");
            //     while(1);
            // } else {
            //     ESP_LOGI(TAG, "malloc buffer from PSRAM successfully");
            //     ESP_LOGI(TAG, "free PSRAM: %d", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
            // }
            ESP_LOGI(TAG, "free PSRAM: %d", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
            lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2, _disp->width() * _disp->height());

            static lv_disp_drv_t disp_drv;
            lv_disp_drv_init(&disp_drv);

            disp_drv.hor_res = _disp->width();
            disp_drv.ver_res = _disp->height();

            disp_drv.flush_cb = _disp_flush;

            disp_drv.draw_buf = &draw_buf_dsc_3;

            lv_disp_drv_register(&disp_drv);
        }

        inline void _lv_port_indev_init()
        {
            /**
             * Here you will find example implementation of input devices supported by LittelvGL:
             *  - Touchpad
             *  - Mouse (with cursor support)
             *  - Keypad (supports GUI usage only with key)
             *  - Encoder (supports GUI usage only with: left, right, push)
             *  - Button (external buttons to press points on the screen)
             *
             *  The `..._read()` function are only examples.
             *  You should shape them according to your hardware
             */
            static lv_indev_drv_t indev_drv;

            /*------------------
             * Touchpad
             * -----------------*/
            /*Register a touchpad input device*/
            lv_indev_drv_init(&indev_drv);
            indev_drv.type = LV_INDEV_TYPE_POINTER;
            indev_drv.read_cb = _touchpad_read;
            // indev_touchpad = lv_indev_drv_register(&indev_drv);
            lv_indev_drv_register(&indev_drv);
        }

    public:
        inline void init(lgfx::LGFX_Device *disp, FT3168::TP_FT3168 *tp)
        {
            _disp = disp;
            _tp = tp;

            lv_init();
            _lv_port_disp_init();
            _lv_port_indev_init();
        }

        inline void update()
        {
            lv_timer_handler();
        }
    };

}

#endif

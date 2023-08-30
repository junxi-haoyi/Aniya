#pragma once

#include "LovyanGFX.hpp"
#include "LovyanGFX/src/lgfx/v1/touch/Touch_CST816S.hpp"
#include "LovyanGFX/src/lgfx/v1/touch/Touch_FT5x06.hpp"

class LGFX : public lgfx::LGFX_Device
{
    lgfx::Panel_ST7789      _panel_instance;

    lgfx::Bus_SPI           _bus_instance;

    // lgfx::Touch_CST816S     _touch_instance;
    // lgfx::Touch_FT5x06           _touch_instance1;


    lgfx::Light_PWM         _light_instance;

public:
    LGFX(void)
    {
        {
            auto cfg = _bus_instance.config();

            cfg.spi_host = SPI2_HOST;
            cfg.spi_mode = 0;
            cfg.freq_write = 80 * 1000 * 1000;
            cfg.freq_read = 16000000;
            cfg.spi_3wire = true;
            cfg.use_lock = true;
            cfg.dma_channel = SPI_DMA_CH_AUTO;

            cfg.pin_sclk = 16;
            cfg.pin_mosi = 17;
            cfg.pin_dc = 7;
            cfg.pin_miso = -1;

            _bus_instance.config(cfg);
            _panel_instance.setBus(&_bus_instance);
        }

        {
            auto cfg = _panel_instance.config();

            cfg.pin_cs = 15;
            cfg.pin_rst = 18;
            cfg.pin_busy = -1;

            cfg.panel_width = 240;
            cfg.panel_height = 280;
            cfg.offset_x = 0;
            cfg.offset_y = 20;
            cfg.offset_rotation = 0;
            cfg.dummy_read_pixel = 8;
            cfg.dummy_read_bits = 1;
            cfg.readable = true;
            cfg.invert = true;
            cfg.rgb_order = true;
            cfg.dlen_16bit = false;
            cfg.bus_shared = true;

            _panel_instance.config(cfg);
        }

        {
            auto cfg = _light_instance.config();

            cfg.pin_bl = 10;
            cfg.invert = true;
            cfg.freq = 44100;
            cfg.pwm_channel = 7;

            _light_instance.config(cfg);
            _panel_instance.setLight(&_light_instance);
        }

        // {
        //     auto cfg = _touch_instance.config();

        //     cfg.x_min = 0;
        //     cfg.x_max = 240;
        //     cfg.y_min = 0;
        //     cfg.y_max = 280;
        //     cfg.pin_int = 46;
        //     cfg.bus_shared = true;
        //     cfg.offset_rotation = 0;

        //     cfg.i2c_port = 1;
        //     cfg.i2c_addr = 0x38;
        //     cfg.pin_sda = 3;
        //     cfg.pin_scl = 8;
        //     cfg.freq = 400000;

        //     _touch_instance.config(cfg);
        //     _panel_instance.setTouch(&_touch_instance);
        // }

        setPanel(&_panel_instance);
    }

    inline bool init(void)
    {
        gpio_reset_pin(GPIO_NUM_9);
        gpio_set_direction(GPIO_NUM_9, GPIO_MODE_OUTPUT);
        gpio_set_pull_mode(GPIO_NUM_9, GPIO_PULLUP_PULLDOWN);
        gpio_set_level(GPIO_NUM_9, 1);

        return lgfx::LGFX_Device::init();
    }
};

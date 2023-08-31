#pragma once

#include "disp/hal_disp.hpp"
#include "lvgl/hal_lvgl.hpp"
#include "disp/hal_qdisp.hpp"
#include "tp/hal_lcd_tp.hpp"
#include "tp/hal_tp.hpp"
#include "sd_card/hal_sd_card.hpp"
#include "power/hal_power.hpp"
#include "rtc/hal_rtc.hpp"
#include "BMI270/hal_BMI270.hpp"

#include <stdio.h>

#include "lgfx/v1/Bus.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class HAL{
    public:

        LGFX lcd_st7789;

        LGFX_OLED qdisp;

        LVGL::LVGL lvgl;

        SD_Card::SD_Card sd_card;

        CST816T::TP_CST816T tp;

        FT3168::TP_FT3168 oled_tp;

        BMI270::BMI270 imu;

        void init();

        void BMI270_init();

        void lcd_St7789_init();

        void lcd_tp_init();

        void qoled_init();

        void clock_test();

        void movingIcons(void);

        void amoled_PwmLightUp(uint8_t num);

        void lcd_PwmLightUp(void);

        void sd_card_init(void);

        void oled_tp_init(void);

};







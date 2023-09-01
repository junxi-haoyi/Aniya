#include "hal.hpp"
#include "disp/hal_qdisp.hpp"
#include "hal_config.h"

LGFX_OLED amoled;

// Copy from https://github.com/Forairaaaaa/monica.git  I don't want write by own
void HAL::BMI270_init(void)
{
    imu.init();
    imu.setWristWearWakeup();
    imu.enableStepCounter();
    gpio_reset_pin(GPIO_NUM_11);
    gpio_set_pull_mode(GPIO_NUM_11, GPIO_FLOATING);
    gpio_set_direction(GPIO_NUM_11, GPIO_MODE_INPUT);
}

void HAL::RTC_init(void)
{
    rtc.init(TP_SDA_PIN, TP_SCL_PIN, RTC_INT_PIN);
}


void HAL::sd_card_init(void)
{
    sd_card.init();
}

void HAL::oled_tp_init(void)
{
    auto cfg = oled_tp.config();
    cfg.pull_up_en = true;
    oled_tp.config(cfg);
    oled_tp.init(TP_SDA_PIN, TP_SCL_PIN, TP_RST_PIN, TP_INT_PIN, true, 400000);
}

void HAL::qoled_init(void)
{
    qdisp.init();
    qdisp.setBrightness(0);
    // qdisp.setColorDepth(24);

    // qdisp.drawFastVLine(50, 50, 200-20, 0xFF0000U);
    // qdisp.drawRect(50, 50, 200, 100, 0xFFFFFFU);
    // qdisp.fillCircle(100, 100, 50, 0xFFFFFFU);
    // sprite.setColorDepth(16);
    // sprite.createSprite(367, 400);
    // sprite.fillScreen(0xFFFFU);
    // sprite.pushSprite(&qdisp, 0, 0);
    // qdisp.display();

    // qdisp.setSwapBytes(true);
    // qdisp.pushImage(17, 35, 334, 334, (void *)gImage_cat24);
    // for (uint8_t i = 1; i < 150; i++)
    // {
    //     qdisp.setBrightness(i);
    //     vTaskDelay(10);
    // }
}

void HAL::amoled_PwmLightUp(uint8_t num)
{
    // qdisp.setSwapBytes(true);
    // qdisp.pushImage(17, 35, 334, 334, (void *)gImage_cat24);
    qdisp.startWrite();
    for (uint8_t i = 1; i < num; i++)
    {
        qdisp.setBrightness(i);
        vTaskDelay(10);
    }
    qdisp.endWrite();
}



void HAL::lcd_St7789_init(void)
{
    lcd_st7789.init();
    lcd_st7789.setBrightness(0);
}

void HAL::lcd_tp_init(void)
{
    auto cfg = tp.config();
    cfg.pull_up_en = false;
    tp.config(cfg);
    tp.init(TP_SDA_PIN, TP_SCL_PIN, TP_RST_PIN, TP_INT_PIN, true, 400000);
}

void HAL::lcd_PwmLightUp(void)
{
    for (uint16_t i = 0; i < 150; i++)
    {
        lcd_st7789.setBrightness(i);
        vTaskDelay(10);
    }
}


/*********************************LovyanGFX Example************************************************/









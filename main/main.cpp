#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "lv_demos.h"
#include "hal.hpp"
#include "myui.h"
#include "ui.h"

HAL Hardware;
MYUI ui;

static void lv_tick_task(void *arg)
{
    (void)arg;

    lv_tick_inc(1);
}

static void lv_HeartBeat(void)
{
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task, .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(
        esp_timer_start_periodic(periodic_timer, 1 * 1000));
}

extern "C" void app_main()
{
    Hardware.sd_card_init();
    Hardware.qoled_init();
    Hardware.oled_tp_init();
    Hardware.lvgl.init(&Hardware.qdisp, &Hardware.oled_tp);
    lv_HeartBeat();
    // lv_demo_music();
    ESP_LOGI("init", "Init OK");

    ui.init();
    // lv_demo_widgets();
    // lv_demo_benchmark();
    // ui_init();
    Hardware.lvgl.update();
    Hardware.amoled_PwmLightUp(150);

    while (1)
    {
        Hardware.lvgl.update();
        vTaskDelay(2);
    }
}

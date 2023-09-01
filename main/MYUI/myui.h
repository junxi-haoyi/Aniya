#pragma once

#include "lvgl.h"
#include "../squareline/ui.h"
#include "../hal/disp/hal_qdisp.hpp"
#include "cJSON.h"
#include "string.h"

#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "aniya_wifi.h"
#include "aniya_ble.h"

#include "ArduinoJson.hpp"

typedef enum _app_states
{
    APP_Undefined = 0,
    APP_Focused,
    APP_Checkout
} app_states;

typedef struct _myui_data
{
    int16_t mvx;
    int16_t mvy;
    int16_t midx;
    int16_t midy;
    int16_t width;
    int16_t height;
    app_states state;
} myui_data;

//////////////////////////////////// ui_main_page ////////////////////////////////////////////
extern myui_data ui_data;
extern myui_data app_brightness_data;

extern lv_obj_t *app_clock;
extern lv_obj_t *app_clock_text_hour;
extern lv_obj_t *app_clock_text_min;
extern lv_obj_t *app_clock_text_week;
extern lv_obj_t *app_clock_text_date;
extern lv_obj_t *app_clock_img;

extern lv_obj_t *app_mood;
extern lv_obj_t *app_mood_img;
extern lv_obj_t *app_mood_tableview;
extern lv_obj_t *app_mood_table;

extern lv_obj_t *app_weather;
extern lv_obj_t *app_watch_face;

extern lv_obj_t *app_wifi;
extern lv_obj_t *app_ble;

extern lv_obj_t *app_brightness;
extern lv_obj_t *app_brightness_img;
extern lv_obj_t *app_brightness_slider;

extern lv_obj_t *app_gif;
extern lv_obj_t *app_aniya;

extern lv_obj_t *ui_page_mian;

//////////////////////////////////// ui_clock_page ////////////////////////////////////////////

class MYUI
{

private:
    static void ui_main_page_init(void);
    static void ble_mian_page_init(void);
    static void ui_clock_page_init(void);
    static void watch_face_page_init(void);

    static void app_clock_event_cb(lv_event_t *e);
    static void main_page_event_cb(lv_event_t *e);
    static void app_brightness_slider_event_cb(lv_event_t *e);
    static void app_brightness_event_cb(lv_event_t *e);

    static void app_mood_img_onCreate(void);
    static void app_clock_text_onCreate(void);
    static void app_clock_text_onDestory(void);
    static void app_brightness_slider_onCreate(void);
    static void app_brightness_slider_onDestory(void);

public:
    MYUI() {}
    ~MYUI() {}

    const char *json_file = "/sdcard/1.json";

    static void anim_up(lv_obj_t *TargetObject, int delay);
    static void anim_scrolldot(lv_obj_t *TargetObject, int delay);
    static void anim_panel_scale2big(lv_obj_t *TargetObject, int delay, int16_t value1, int16_t value2);
    static void anim_panel_scale2small(lv_obj_t *TargetObject, int delay, int16_t value1, int16_t value2);
    static void anim_come_out(lv_obj_t *TargetObject, int delay, int16_t value);
    static void anim_opa(lv_obj_t *TargetObject, int delay, int16_t opa1, int16_t opa2); // transparency animotion
    static void anim_move_x(lv_obj_t *TargetObject, int delay, int16_t x);               // move x animotion
    static void anim_move_y(lv_obj_t *TargetObject, int delay, int16_t y);               // move y animotion
    static void app_focused(lv_obj_t *TargetObject, int delay, myui_data *ui_data);

    static void app_clock_init(void);
    static void app_clock_task(void *params);
    static void app_clock_task_create(void);

    static void app_weather_init(void);

    static void app_mood_init(void);

    static void app_watch_face_init(void);

    static void app_wifi_init(void);

    static void app_ble_init(void);

    static void app_brightness_init(void);

    static void app_gif_init(void);

    static void app_aniya_init(void);

    static void app_event_cb_init(void);

    void init(void);

    void json_test(void);
};

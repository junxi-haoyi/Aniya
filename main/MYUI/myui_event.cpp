#include "myui.h"

LGFX_OLED pwm;

void MYUI::app_clock_event_cb(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_SHORT_CLICKED && ui_data.state != APP_Focused)
    {
        ui_data.midx = lv_obj_get_x(app_clock) + lv_obj_get_width(app_clock) / 2;
        ui_data.midy = lv_obj_get_y(app_clock) + lv_obj_get_height(app_clock) / 2;

        ui_data.mvx = 105;
        ui_data.mvy = 0;
        ui_data.width = 210;
        ui_data.height = 0;

        app_focused(app_clock, 0, &ui_data);
        anim_move_x(app_weather, 0, ui_data.mvx + 110);
        anim_move_x(app_clock_text_hour, 0, -ui_data.mvx);
        anim_move_x(app_clock_text_min, 0, -ui_data.mvx);

        app_clock_text_onCreate();

        lv_obj_clear_flag(ui_page_mian, LV_OBJ_FLAG_SCROLLABLE);
        ui_data.state = APP_Focused;

        return;
    }

    if (event_code == LV_EVENT_SHORT_CLICKED && ui_data.state == APP_Focused)
    {
        lv_event_code_t event_code = lv_event_get_code(e);
        lv_obj_t *target = lv_event_get_target(e);

        ui_data.mvx = -105;
        ui_data.mvy = 0;
        ui_data.width = -210;
        ui_data.height = 0;

        app_focused(app_clock, 0, &ui_data);
        anim_move_x(app_weather, 0, ui_data.mvx - 110);
        anim_move_x(app_clock_text_hour, 0, -ui_data.mvx);
        anim_move_x(app_clock_text_min, 0, -ui_data.mvx);

        app_clock_text_onDestory();

        ui_data.state = APP_Checkout;
    }
}

void MYUI::main_page_event_cb(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);

    if (event_code == LV_EVENT_SCREEN_LOADED)
    {
        anim_panel_scale2big(app_clock, 1600, 130, 160);
        anim_panel_scale2big(app_weather, 1800, 195, 160);
        anim_panel_scale2big(app_mood, 2000, 100, 100);
        anim_panel_scale2big(app_watch_face, 1700, 230, 100);
        anim_panel_scale2big(app_wifi, 2200, 110, 60);
        anim_panel_scale2big(app_ble, 2400, 110, 60);
        anim_panel_scale2big(app_brightness, 2600, 110, 60);
        anim_panel_scale2big(app_gif, 2800, 170, 75);
        anim_panel_scale2big(app_aniya, 2800, 160, 75);
    }
}

void MYUI::app_brightness_event_cb(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);

    if (event_code == LV_EVENT_SHORT_CLICKED && app_brightness_data.state != APP_Focused)
    {
        app_brightness_data.mvx = -120;
        app_brightness_data.mvy = 0;

        app_brightness_data.width = 225;
        app_brightness_data.height = 0;

        app_focused(app_brightness, 0, &app_brightness_data);
        anim_move_x(app_brightness_img, 0, -130);
        anim_move_x(app_wifi, 0, -140);
        anim_move_x(app_ble, 0, -250);
        app_brightness_slider_onCreate();
        app_brightness_data.state = APP_Focused;
        return;
    }

    if (event_code == LV_EVENT_SHORT_CLICKED && app_brightness_data.state == APP_Focused && target == app_brightness_img)
    {
        app_brightness_data.mvx = 120;
        app_brightness_data.mvy = 0;

        app_brightness_data.width = -225;
        app_brightness_data.height = 0;

        app_focused(app_brightness, 0, &app_brightness_data);
        anim_move_x(app_brightness_img, 0, 130);
        anim_move_x(app_wifi, 0, 140);
        anim_move_x(app_ble, 0, 250);
        app_brightness_slider_onDestory();

        app_brightness_data.state = APP_Checkout;
        return;
    }
}

void MYUI::app_brightness_slider_event_cb(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);

    uint16_t brghtness = lv_slider_get_value(app_brightness_slider);
    pwm.setBrightness(brghtness);
}

void MYUI::app_clock_text_onCreate(void)
{
    app_clock_text_date = lv_label_create(app_clock);
    lv_obj_set_width(app_clock_text_date, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_clock_text_date, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(app_clock_text_date, 0);
    lv_obj_set_y(app_clock_text_date, -35);
    lv_obj_set_align(app_clock_text_date, LV_ALIGN_CENTER);
    lv_label_set_text(app_clock_text_date, "Date: 8.23");
    lv_obj_set_style_text_color(app_clock_text_date, lv_color_hex(0xe77c8e), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_clock_text_date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_clock_text_date, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_clock_text_week = lv_label_create(app_clock);
    lv_obj_set_width(app_clock_text_week, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_clock_text_week, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(app_clock_text_week, 5);
    lv_obj_set_y(app_clock_text_week, 23);
    lv_obj_set_align(app_clock_text_week, LV_ALIGN_CENTER);
    lv_label_set_text(app_clock_text_week, "week: Wed");
    lv_obj_set_style_text_color(app_clock_text_week, lv_color_hex(0xe77c8e), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_clock_text_week, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_clock_text_week, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_clock_img = lv_img_create(app_clock);
    lv_img_set_src(app_clock_img, "/sdcard/pic/thinking.png");
    lv_obj_set_width(app_clock_img, LV_SIZE_CONTENT);  /// 64
    lv_obj_set_height(app_clock_img, LV_SIZE_CONTENT); /// 64
    lv_obj_set_x(app_clock_img, 120);
    lv_obj_set_y(app_clock_img, 0);
    lv_obj_set_align(app_clock_img, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_clock_img, LV_OBJ_FLAG_SCROLLABLE);
}

void MYUI::app_clock_text_onDestory(void)
{
    lv_obj_del(app_clock_text_date);
    lv_obj_del(app_clock_text_week);
    lv_obj_del(app_clock_img);
}

void MYUI::app_mood_img_onCreate(void)
{
    app_mood_tableview = lv_tabview_create(app_mood, LV_DIR_TOP, 0);
    lv_obj_set_width(app_mood_tableview, 100);
    lv_obj_set_height(app_mood_tableview, 100);
    lv_obj_set_align(app_mood_tableview, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_mood_tableview, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(app_mood_tableview, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(app_mood_tableview, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_mood_tableview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_fs_dir_t dir;
    lv_fs_res_t res;

    res = lv_fs_dir_open(&dir, "/sdcard/pic/mood");
    if (res != LV_FS_RES_OK)
    {
        ESP_LOGI("SD", "fail to open");
    }

    char fn[50];
    uint8_t num = 1;
    while (1)
    {
        res = lv_fs_dir_read(&dir, fn);
        if (res != LV_FS_RES_OK)
        {
            ESP_LOGE("SD", "fail to open");
            break;
        }

        if (strlen(fn) == 0)
        {
            break;
        }

        app_mood_table = lv_tabview_add_tab(app_mood_tableview, fn);
        lv_obj_set_style_bg_color(app_mood_table, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(app_mood_table, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(app_mood_table, LV_OBJ_FLAG_SCROLLABLE);

        sprintf(fn, "/sdcard/pic/mood/%d.png", num);
        app_mood_img = lv_img_create(app_mood_table);
        lv_img_set_src(app_mood_img, fn);
        lv_obj_set_width(app_mood_img, LV_SIZE_CONTENT);  /// 256
        lv_obj_set_height(app_mood_img, LV_SIZE_CONTENT); /// 256
        lv_obj_set_align(app_mood_img, LV_ALIGN_CENTER);
        lv_obj_clear_flag(app_mood_img, LV_OBJ_FLAG_SCROLLABLE);

        num++;
    }

    lv_fs_dir_close(&dir);
}

void MYUI::app_brightness_slider_onCreate(void)
{
    app_brightness_slider = lv_slider_create(app_brightness);
    lv_slider_set_range(app_brightness_slider, 50, 255);
    lv_slider_set_value(app_brightness_slider, 150, LV_ANIM_OFF);
    lv_obj_set_width(app_brightness_slider, 228);
    lv_obj_set_height(app_brightness_slider, 30);
    lv_obj_set_x(app_brightness_slider, 43);
    lv_obj_set_y(app_brightness_slider, 0);
    lv_obj_set_align(app_brightness_slider, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(app_brightness_slider, lv_color_hex(0xEE3F4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_brightness_slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(app_brightness_slider, lv_color_hex(0xEEA2A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(app_brightness_slider, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_brightness_slider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(app_brightness_slider, lv_color_hex(0xD11A2D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_brightness_slider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_brightness_slider, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(app_brightness_slider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_brightness_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(app_brightness_slider, app_brightness_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

void MYUI::app_brightness_slider_onDestory(void)
{
    lv_obj_del(app_brightness_slider);
    lv_obj_remove_event_cb(app_brightness_slider, app_brightness_slider_event_cb);
}
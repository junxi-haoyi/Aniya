#include "../myui.h"




void MYUI::app_clock_init(void)
{
    app_clock = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_clock, 130);
    lv_obj_set_height(app_clock, 130);
    lv_obj_set_x(app_clock, -105);
    lv_obj_set_y(app_clock, -130);
    lv_obj_set_align(app_clock, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_clock, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_clock, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_clock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_clock, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_clock_text_hour = lv_label_create(app_clock);
    lv_obj_set_width(app_clock_text_hour, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_clock_text_hour, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(app_clock_text_hour, 0);
    lv_obj_set_y(app_clock_text_hour, -35);
    lv_obj_set_align(app_clock_text_hour, LV_ALIGN_CENTER);
    lv_label_set_text(app_clock_text_hour, "10");
    lv_obj_set_style_text_color(app_clock_text_hour, lv_color_hex(0xe77c8e), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_clock_text_hour, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_clock_text_hour, &ui_font_mont80, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_clock_text_min = lv_label_create(app_clock);
    lv_obj_set_width(app_clock_text_min, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_clock_text_min, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(app_clock_text_min, 0);
    lv_obj_set_y(app_clock_text_min, 35);
    lv_obj_set_align(app_clock_text_min, LV_ALIGN_CENTER);
    lv_label_set_text(app_clock_text_min, "34");
    lv_obj_set_style_text_color(app_clock_text_min, lv_color_hex(0xec2c64), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_clock_text_min, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_clock_text_min, &ui_font_mont80, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void MYUI::app_weather_init(void)
{
    app_weather = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_weather, 165);
    lv_obj_set_height(app_weather, 160);
    lv_obj_set_x(app_weather, 65);
    lv_obj_set_y(app_weather, -130);
    lv_obj_set_align(app_weather, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_weather, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_weather, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_weather, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_weather, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_weather_text = lv_label_create(app_weather);
    lv_obj_set_width(app_weather_text, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_weather_text, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(app_weather_text, 35);
    lv_obj_set_y(app_weather_text, -19);
    lv_obj_set_align(app_weather_text, LV_ALIGN_CENTER);
    lv_label_set_text(app_weather_text, "weather");
    lv_obj_set_style_text_color(app_weather_text, lv_color_hex(0xec2c64), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_weather_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_weather_text, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_weather_temp = lv_label_create(app_weather);
    lv_obj_set_width(app_weather_temp, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_weather_temp, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(app_weather_temp, -49);
    lv_obj_set_y(app_weather_temp, 36);
    lv_obj_set_align(app_weather_temp, LV_ALIGN_CENTER);
    lv_label_set_text(app_weather_temp, "Tem:25");
    lv_obj_set_style_text_color(app_weather_temp, lv_color_hex(0xec2c64), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_weather_temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_weather_temp, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_weather_img = lv_img_create(app_weather);
    lv_img_set_src(app_weather_img, "/sdcard/pic/weather/rainbow.png");
    lv_obj_set_width(app_weather_img, LV_SIZE_CONTENT);  /// 64
    lv_obj_set_height(app_weather_img, LV_SIZE_CONTENT); /// 64
    lv_obj_set_x(app_weather_img, -53);
    lv_obj_set_y(app_weather_img, -27);
    lv_obj_set_align(app_weather_img, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_weather_img, LV_OBJ_FLAG_SCROLLABLE);
}

void MYUI::app_mood_init(void)
{
    app_mood = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_mood, 100);
    lv_obj_set_height(app_mood, 100);
    lv_obj_set_x(app_mood, -120);
    lv_obj_set_y(app_mood, 8);
    lv_obj_set_align(app_mood, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_mood, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_mood, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_mood, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

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

void MYUI::app_watch_face_init(void)
{
    app_watch_face = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_watch_face, 225);
    lv_obj_set_height(app_watch_face, 100);
    lv_obj_set_x(app_watch_face, 50);
    lv_obj_set_y(app_watch_face, 8);
    lv_obj_set_align(app_watch_face, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_watch_face, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_watch_face, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_watch_face, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_watch_face, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // app_watch_face_button1 = lv_btn_create(app_watch_face);
    // lv_obj_set_width(app_watch_face_button1, 64);
    // lv_obj_set_height(app_watch_face_button1, 64);
    // lv_obj_set_x(app_watch_face, 20);
    // lv_obj_set_y(app_watch_face, 0);
    // lv_obj_set_align(app_watch_face_button1, LV_ALIGN_CENTER);
    // lv_obj_add_flag(app_watch_face_button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    // lv_obj_clear_flag(app_watch_face_button1, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    app_watch_face_img = lv_img_create(app_watch_face);
    lv_img_set_src(app_watch_face_img, "/sdcard/pic/sys/watch.png");
    lv_obj_set_width(app_watch_face_img, LV_SIZE_CONTENT);  /// 256
    lv_obj_set_height(app_watch_face_img, LV_SIZE_CONTENT); /// 256
    // lv_obj_set_x(app_watch_face_img, -70);
    // lv_obj_set_y(app_watch_face_img, 0);
    lv_obj_set_align(app_watch_face_img, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(app_watch_face_img, LV_OBJ_FLAG_SCROLLABLE);

    app_watch_face_text = lv_label_create(app_watch_face);
    lv_obj_set_width(app_watch_face_text, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_watch_face_text, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(app_watch_face_text, 34);
    lv_obj_set_y(app_watch_face_text, 0);
    lv_obj_set_align(app_watch_face_text, LV_ALIGN_CENTER);
    lv_label_set_text(app_watch_face_text, "watch face");
    lv_obj_set_style_text_color(app_watch_face_text, lv_color_hex(0xec2c64), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_watch_face_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_watch_face_text, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void MYUI::app_wifi_init(void)
{
    app_wifi = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_wifi, 110);
    lv_obj_set_height(app_wifi, 60);
    lv_obj_set_x(app_wifi, -115);
    lv_obj_set_y(app_wifi, 95);
    lv_obj_set_align(app_wifi, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_wifi, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_wifi, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_wifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_wifi, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_wifi_img = lv_img_create(app_wifi);
    lv_img_set_src(app_wifi_img, "/sdcard/pic/sys/wifi.png");
    lv_obj_set_width(app_wifi_img, LV_SIZE_CONTENT);  /// 256
    lv_obj_set_height(app_wifi_img, LV_SIZE_CONTENT); /// 256
    lv_obj_set_align(app_wifi_img, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_wifi_img, LV_OBJ_FLAG_SCROLLABLE);
}

void MYUI::app_ble_init(void)
{
    app_ble = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_ble, 110);
    lv_obj_set_height(app_ble, 60);
    lv_obj_set_x(app_ble, 0);
    lv_obj_set_y(app_ble, 95);
    lv_obj_set_align(app_ble, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_ble, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_ble, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_ble, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_ble, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_ble_img = lv_img_create(app_ble);
    lv_img_set_src(app_ble_img, "/sdcard/pic/sys/ble.png");
    lv_obj_set_width(app_ble_img, LV_SIZE_CONTENT);  /// 256
    lv_obj_set_height(app_ble_img, LV_SIZE_CONTENT); /// 256
    lv_obj_set_align(app_ble_img, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_ble_img, LV_OBJ_FLAG_SCROLLABLE);
}

void MYUI::app_brightness_init(void)
{
    app_brightness = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_brightness, 110);
    lv_obj_set_height(app_brightness, 60);
    lv_obj_set_x(app_brightness, 115);
    lv_obj_set_y(app_brightness, 95);
    lv_obj_set_align(app_brightness, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_brightness, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_add_flag(app_brightness, LV_OBJ_FLAG_CLICKABLE);    /// Flags
    lv_obj_set_style_bg_color(app_brightness, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_brightness, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_brightness, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_brightness_img = lv_img_create(app_brightness);
    lv_img_set_src(app_brightness_img, "/sdcard/pic/sys/bright.png");
    lv_obj_set_width(app_brightness_img, LV_SIZE_CONTENT);  /// 256
    lv_obj_set_height(app_brightness_img, LV_SIZE_CONTENT); /// 256
    lv_obj_set_align(app_brightness_img, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_brightness_img, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(app_brightness_img, LV_OBJ_FLAG_CLICKABLE); /// Flags
}

void MYUI::app_gif_init(void)
{
    app_gif = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_gif, 170);
    lv_obj_set_height(app_gif, 75);
    lv_obj_set_x(app_gif, -85);
    lv_obj_set_y(app_gif, 167);
    lv_obj_set_align(app_gif, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_gif, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_gif, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_gif, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_gif, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_gif_item = lv_gif_create(app_gif);
    lv_gif_set_src(app_gif_item, "/sdcard/gif/neoncat.gif");
    lv_obj_set_width(app_gif_item, LV_SIZE_CONTENT);  /// 256
    lv_obj_set_height(app_gif_item, LV_SIZE_CONTENT); /// 256
    lv_obj_set_align(app_gif_item, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_gif_item, LV_OBJ_FLAG_SCROLLABLE);
}

void MYUI::app_aniya_init(void)
{
    app_aniya = lv_obj_create(ui_page_mian);
    lv_obj_set_width(app_aniya, 160);
    lv_obj_set_height(app_aniya, 75);
    lv_obj_set_x(app_aniya, 90);
    lv_obj_set_y(app_aniya, 167);
    lv_obj_set_align(app_aniya, LV_ALIGN_CENTER);
    lv_obj_clear_flag(app_aniya, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(app_aniya, lv_color_hex(0x55FCBB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(app_aniya, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(app_aniya, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    app_aniya_text = lv_label_create(app_aniya);
    lv_obj_set_width(app_aniya_text, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(app_aniya_text, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(app_aniya_text, LV_ALIGN_CENTER);
    lv_label_set_text(app_aniya_text, "steps:0");
    lv_obj_set_style_text_color(app_aniya_text, lv_color_hex(0xec2c64), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(app_aniya_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(app_aniya_text, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void MYUI::app_event_cb_init(void)
{
    lv_obj_add_event_cb(app_brightness, app_brightness_event_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(app_brightness_img, app_brightness_event_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(app_clock, app_clock_event_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_page_mian, main_page_event_cb, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(app_watch_face, app_watch_face_event_cb, LV_EVENT_SHORT_CLICKED, NULL);
}

void MYUI::ui_main_page_init(void)
{
    ui_page_mian = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(ui_page_mian, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_page_mian, LV_DIR_VER);
    lv_obj_set_style_radius(ui_page_mian, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_page_mian, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_page_mian, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ///////////////////////******* app_clock *******////////////////////////////////////
    app_clock_init();
    ///////////////////////******* app_weather *******////////////////////////////////////
    app_weather_init();
    ///////////////////////******* app_mood *******////////////////////////////////////
    app_mood_init();

    ///////////////////////******* app_watchface *******////////////////////////////////////
    app_watch_face_init();

    ///////////////////////******* app_wifi *******////////////////////////////////////
    app_wifi_init();

    ///////////////////////******* app_ble *******////////////////////////////////////
    app_ble_init();

    ///////////////////////******* app_brightness *******////////////////////////////////////
    app_brightness_init();

    ///////////////////////******* app_gif *******////////////////////////////////////
    app_gif_init();

    ///////////////////////******* app_aniya *******////////////////////////////////////
    app_aniya_init();

    app_event_cb_init();
}





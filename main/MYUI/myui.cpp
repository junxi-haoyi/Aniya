#include "myui.h"

myui_data app_clock_data;
myui_data app_brightness_data;
myui_data app_watch_face_data;

//////////////////////////////////// ui_main_page ////////////////////////////////////////////

lv_obj_t *app_clock;
lv_obj_t *app_clock_text_hour;
lv_obj_t *app_clock_text_min;
lv_obj_t *app_clock_text_week;
lv_obj_t *app_clock_text_date;
lv_obj_t *app_clock_img;
lv_obj_t *app_clock_sec_img;
lv_obj_t *app_clock_hour_img;
lv_obj_t *app_clock_min_img;


lv_obj_t *app_mood;
lv_obj_t *app_mood_img;
lv_obj_t *app_mood_tableview;
lv_obj_t *app_mood_table;

lv_obj_t *app_weather;
lv_obj_t *app_weather_img;
lv_obj_t *app_weather_text;
lv_obj_t *app_weather_temp;

lv_obj_t *app_watch_face;
lv_obj_t *app_watch_face_text;
lv_obj_t *app_watch_face_img;
lv_obj_t *app_watch_face_selector;
lv_obj_t *app_watch_face_button;
lv_obj_t *app_watch_face_button_text;

lv_obj_t *app_wifi;
lv_obj_t *app_wifi_img;

lv_obj_t *app_ble;
lv_obj_t *app_ble_img;

lv_obj_t *app_brightness;
lv_obj_t *app_brightness_slider;
lv_obj_t *app_brightness_img;

lv_obj_t *app_gif;
lv_obj_t *app_gif_item;

lv_obj_t *app_aniya;
lv_obj_t *app_aniya_text;

//////////////////////////////////// ui_watch_face_page ////////////////////////////////////////////
lv_obj_t *aniya_img;
lv_obj_t *aniya_label_time;
lv_obj_t *aniya_label_date;
//////////////////////////////////// ui_page ////////////////////////////////////////////
lv_obj_t *ui_page_mian;
lv_obj_t *ble_page_main;
lv_obj_t *watch_face_page;
lv_obj_t *clock_pointer_page;




void MYUI::ui_clock_page_init(void)
{
}

void MYUI::watch_face_page_init(void)
{
    watch_face_page = lv_obj_create(NULL);
    lv_obj_clear_flag(watch_face_page, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(watch_face_page, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(watch_face_page, lv_color_hex(0xE77C8E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(watch_face_page, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    aniya_img = lv_img_create(watch_face_page);
    lv_img_set_src(aniya_img, "/sdcard/aniya/1.png");
    lv_obj_set_width(aniya_img, LV_SIZE_CONTENT);  /// 384
    lv_obj_set_height(aniya_img, LV_SIZE_CONTENT); /// 412
    lv_obj_set_x(aniya_img, 0);
    lv_obj_set_y(aniya_img, 22);
    lv_obj_set_align(aniya_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(aniya_img, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(aniya_img, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    aniya_label_time = lv_label_create(watch_face_page);
    lv_obj_set_width(aniya_label_time, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(aniya_label_time, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(aniya_label_time, -100);
    lv_obj_set_y(aniya_label_time, -180);
    lv_obj_set_align(aniya_label_time, LV_ALIGN_CENTER);
    lv_label_set_text(aniya_label_time, "10:34");
    lv_obj_set_style_text_font(aniya_label_time, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    aniya_label_date = lv_label_create(watch_face_page);
    lv_obj_set_width(aniya_label_date, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(aniya_label_date, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(aniya_label_date, 100);
    lv_obj_set_y(aniya_label_date, -180);
    lv_obj_set_align(aniya_label_date, LV_ALIGN_CENTER);
    lv_label_set_text(aniya_label_date, "Sun");
    lv_obj_set_style_text_font(aniya_label_date, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void MYUI::init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    ui_main_page_init();
    watch_face_page_init();
    clock_pointer_page_init();

    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_page_mian);
}

void MYUI::json_test(void)
{
    // lv_fs_dir_t dir;
    // lv_fs_res_t res;

    // // res = lv_fs_dir_open(&dir, "/sdcard/1.json");
    // // if (res != LV_FS_RES_OK)
    // // {
    // //     ESP_LOGI("SD", "fail to open");
    // // }

    // char fn[256];
    // while (1)
    // {
    //     res = lv_fs_dir_read(&dir, fn);
    //     if (res != LV_FS_RES_OK)
    //     {
    //         ESP_LOGE("SD", "fail to open");
    //         break;
    //     }

    //     if (strlen(fn) == 0)
    //     {
    //         break;
    //     }

    //     printf("%s\n", fn);
    // }

    // lv_fs_dir_close(&dir);
    // char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
    // ArduinoJson::V6213HB2::DynamicJsonDocument doc(1024);
    // deserializeJson(doc, json);

    // const char *sensor = doc["sensor"];
    // long time = doc["time"];
    // double latitude = doc["data"][0];
    // double longitude = doc["data"][1];
    // printf("%s\n", sensor);
    // printf("%ld\n", time);
    // printf("%f\n", latitude);
    // printf("%f\n", longitude);

    // FILE *f = fopen("/sdcard/hello.json", "r");
    // if(f == NULL)
    // {
    //     ESP_LOGE("json", "Failed to open");
    //     fclose(f);
    //     return;
    // }
    // char line[64];
    // fgets(line, sizeof(line), f);
    // printf("%s\n", line);
    // fgets(line, sizeof(line), f);
    // printf("%s\n", line);
    // fgets(line, sizeof(line), f);
    // printf("%s\n", line);

    // fclose(f);
}

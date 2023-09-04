#include "../myui.h"




void MYUI::clock_pointer_page_init(void)
{
    clock_pointer_page = lv_obj_create(NULL);
    lv_obj_clear_flag(clock_pointer_page, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(clock_pointer_page, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(clock_pointer_page, lv_color_hex(0xEEA2A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(clock_pointer_page, 255, LV_PART_MAIN | LV_STATE_DEFAULT);


    app_clock_sec_img = lv_img_create(clock_pointer_page);
    lv_img_set_src(app_clock_sec_img, &ui_img_clockwise_sec_png);
    lv_obj_set_width(app_clock_sec_img, LV_SIZE_CONTENT);   /// 31
    lv_obj_set_height(app_clock_sec_img, LV_SIZE_CONTENT);    /// 180
    lv_obj_set_x(app_clock_sec_img, 0);
    lv_obj_set_y(app_clock_sec_img, -67);
    lv_obj_set_align(app_clock_sec_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(app_clock_sec_img, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(app_clock_sec_img, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(app_clock_sec_img, 15, 155);
    lv_img_set_angle(app_clock_sec_img, 12000);


    app_clock_min_img = lv_img_create(clock_pointer_page);
    lv_img_set_src(app_clock_min_img, &ui_img_clockwise_min_png);
    lv_obj_set_width(app_clock_min_img, LV_SIZE_CONTENT);   /// 18
    lv_obj_set_height(app_clock_min_img, LV_SIZE_CONTENT);    /// 157
    lv_obj_set_x(app_clock_min_img, 0);
    lv_obj_set_y(app_clock_min_img, -75);
    lv_obj_set_align(app_clock_min_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(app_clock_min_img, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(app_clock_min_img, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(app_clock_min_img, 9, 153);



    app_clock_hour_img = lv_img_create(clock_pointer_page);
    lv_img_set_src(app_clock_hour_img, &ui_img_clockwise_hour_png);
    lv_obj_set_width(app_clock_hour_img, LV_SIZE_CONTENT);   /// 18
    lv_obj_set_height(app_clock_hour_img, LV_SIZE_CONTENT);    /// 98
    lv_obj_set_x(app_clock_hour_img, 0);
    lv_obj_set_y(app_clock_hour_img, -45);
    lv_obj_set_align(app_clock_hour_img, LV_ALIGN_CENTER);
    lv_obj_add_flag(app_clock_hour_img, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(app_clock_hour_img, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(app_clock_hour_img, 9, 93);

    lv_obj_add_event_cb(clock_pointer_page, clock_pointer_page_event_cb, LV_EVENT_ALL, NULL);
}






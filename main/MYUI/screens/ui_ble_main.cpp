#include "../myui.h"




void MYUI::ble_mian_page_init(void)
{
    ble_page_main = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(ble_page_main, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ble_page_main, LV_DIR_VER);
    lv_obj_set_style_radius(ble_page_main, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ble_page_main, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ble_page_main, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}





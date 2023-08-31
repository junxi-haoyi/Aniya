/**
 * @file hal_power.hpp
 * @author junxi-haoyi
 * @brief 
 * @version 0.1
 * @date 2023-08-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <driver/i2c.h>
#include <esp_log.h>
#include <stdio.h>


namespace BMI270{
    static const char* TAG = "AXP2101"

    struct Config_t {
        int pin_scl = -1;
        int pin_sda = -1;
        int pin_int = -1;
        i2c_port_t i2c_port = 0;

        
    };


}
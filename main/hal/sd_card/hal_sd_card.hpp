#pragma once



#include <iostream>
#include "driver/sdmmc_host.h"
#include "sdmmc_cmd.h"
#include "esp_vfs_fat.h"
#include "string.h"
#include "esp_log.h"
#include "hal_config.h"



namespace SD_Card{
    static const char* TAG = "SD";

    struct Config_t {
        int CMD = SD_CMD_PIN;
        int CLK = SD_CLK_PIN;
        int D0 = SD_D0_PIN;
        int D1 = SD_D1_PIN;
        int D2 = SD_D2_PIN;
        int D3 = SD_D3_PIN;

        std::string MOUNTPOINT = "/sdcard";
        bool formatIfMountFailed = true;
    };

    class SD_Card{
        private :
            Config_t _config;
            bool _available;

        public:
            SD_Card() : _available(false) {}
            ~SD_Card() {}

            inline void config(Config_t cfg) { _config = cfg; }
            inline Config_t config(void) { return _config; }

            inline bool isAvailable() {return _available; }


            inline void init()
            {
                esp_err_t ret;

                esp_vfs_fat_sdmmc_mount_config_t mount_config;
                mount_config.format_if_mount_failed = _config.formatIfMountFailed;
                mount_config.max_files = 5;
                mount_config.allocation_unit_size = 16 * 1024;
                mount_config.disk_status_check_enable = false;
                sdmmc_card_t *card;
                ESP_LOGI(TAG, "Initializing SD card");

                ESP_LOGI(TAG, "Using SDMMC peripheral");

                sdmmc_host_t host = SDMMC_HOST_DEFAULT();
                // host.max_freq_khz = SDMMC_FREQ_HIGHSPEED;

                sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

                slot_config.width = 4;

                slot_config.clk = (gpio_num_t)_config.CLK;
                slot_config.cmd = (gpio_num_t)_config.CMD;
                slot_config.d0 = (gpio_num_t)_config.D0;
                slot_config.d1 = (gpio_num_t)_config.D1;
                slot_config.d2 = (gpio_num_t)_config.D2;
                slot_config.d3 = (gpio_num_t)_config.D3;

                ESP_LOGI(TAG, "Mounting filesystem");

                ret = esp_vfs_fat_sdmmc_mount(_config.MOUNTPOINT.c_str(), &host, &slot_config, &mount_config, &card);

                if(ret != ESP_OK) {
                    if(ret == ESP_FAIL) {
                        ESP_LOGE(TAG, "Failed to mount filesystem"
                                        "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
                    } else {
                        ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                                    "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));

                    }
                    return;
                }

                ESP_LOGI(TAG, "Filesystem mounted");

                sdmmc_card_print_info(stdout, card);

                _available = true;
            }
    };
    
};





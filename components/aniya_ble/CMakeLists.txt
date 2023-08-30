idf_component_register(SRCS "aniya_ble.c"
                            "esp_hidd_prf_api.c"
                            "hid_dev.c"
                            "hid_device_le_prf.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_event bt nvs_flash driver
                    )

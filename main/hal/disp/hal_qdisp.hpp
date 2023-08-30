#pragma once

#include "LovyanGFX.hpp"
#include "lgfx/v1/platforms/esp32/Bus_QSPI.hpp"

class LGFX_OLED : public lgfx::LGFX_Device
{
    lgfx::Panel_SH8601Z _panel_instance;

    lgfx::Bus_QSPI _bus_instance;

public:
    LGFX_OLED(void)
    {
        {
            auto cfg = _bus_instance.config();

            cfg.spi_host = SPI2_HOST;
            cfg.spi_mode = 0;
            cfg.freq_write = 60 * 1000 * 1000;
            // cfg.spi_3wire  = true;
            cfg.freq_read = 16000000;
            cfg.use_lock = true;
            cfg.dma_channel = SPI_DMA_CH_AUTO;

            cfg.pin_sclk = 4;
            cfg.pin_io0 = 6;
            cfg.pin_io1 = 5;
            cfg.pin_io2 = 2;
            cfg.pin_io3 = 1;

            _bus_instance.config(cfg);
            _panel_instance.setBus(&_bus_instance);
        }

        {
            auto cfg = _panel_instance.config();

            cfg.pin_cs = 3;
            cfg.pin_rst = 7;
            cfg.pin_busy = -1;

            cfg.panel_width = 368;
            cfg.panel_height = 448;

            cfg.offset_x = 0;
            cfg.offset_y = 0;
            cfg.offset_rotation = 0;
            cfg.dummy_read_pixel = 8;
            cfg.dummy_read_bits = 1;
            cfg.readable = true;
            cfg.invert = true;
            cfg.rgb_order = true;
            cfg.dlen_16bit = false;
            cfg.bus_shared = true;

            cfg.memory_width = 450;
            cfg.memory_height = 450;

            _panel_instance.config(cfg);
        }
        setPanel(&_panel_instance);
    }

    inline bool init(void)
    {
        gpio_reset_pin(GPIO_NUM_3);
        gpio_set_direction(GPIO_NUM_3, GPIO_MODE_OUTPUT);
        gpio_set_pull_mode(GPIO_NUM_3, GPIO_PULLUP_PULLDOWN);
        gpio_set_level(GPIO_NUM_3, 1);

        gpio_reset_pin(GPIO_NUM_41);
        gpio_set_direction(GPIO_NUM_41, GPIO_MODE_OUTPUT);
        gpio_set_pull_mode(GPIO_NUM_41, GPIO_PULLUP_PULLDOWN);
        gpio_set_level(GPIO_NUM_41, 1);

        // gpio_reset_pin(GPIO_NUM_10);
        // gpio_set_direction(GPIO_NUM_10, GPIO_MODE_OUTPUT);
        // gpio_set_pull_mode(GPIO_NUM_10, GPIO_PULLUP_PULLDOWN);
        // gpio_set_level(GPIO_NUM_10, 1);

        // gpio_reset_pin(GPIO_NUM_9);
        // gpio_set_direction(GPIO_NUM_9, GPIO_MODE_INPUT);

        return lgfx::LGFX_Device::init();
    }
};

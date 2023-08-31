#include "hal.hpp"
#include "disp/hal_qdisp.hpp"
#include "hal_config.h"

LGFX_OLED amoled;

// Copy from https://github.com/Forairaaaaa/monica.git  I don't want write by own
void HAL::BMI270_init(void)
{
    imu.init();
    imu.setWristWearWakeup();
    imu.enableStepCounter();
    gpio_reset_pin(GPIO_NUM_11);
    gpio_set_pull_mode(GPIO_NUM_11, GPIO_FLOATING);
    gpio_set_direction(GPIO_NUM_11, GPIO_MODE_INPUT);
}



void HAL::sd_card_init(void)
{
    sd_card.init();
}

void HAL::lcd_St7789_init(void)
{
    lcd_st7789.init();
    lcd_st7789.setBrightness(0);
}

void HAL::lcd_tp_init(void)
{
    auto cfg = tp.config();
    cfg.pull_up_en = false;
    tp.config(cfg);
    tp.init(TP_SDA_PIN, TP_SCL_PIN, TP_RST_PIN, TP_INT_PIN, true, 400000);
}

void HAL::oled_tp_init(void)
{
    auto cfg = oled_tp.config();
    cfg.pull_up_en = true;
    oled_tp.config(cfg);
    oled_tp.init(TP_SDA_PIN, TP_SCL_PIN, TP_RST_PIN, TP_INT_PIN, true, 400000);
}

void HAL::lcd_PwmLightUp(void)
{
    for (uint16_t i = 0; i < 150; i++)
    {
        lcd_st7789.setBrightness(i);
        vTaskDelay(10);
    }
}

void HAL::qoled_init(void)
{
    qdisp.init();
    qdisp.setBrightness(0);
    // qdisp.setColorDepth(24);

    // qdisp.drawFastVLine(50, 50, 200-20, 0xFF0000U);
    // qdisp.drawRect(50, 50, 200, 100, 0xFFFFFFU);
    // qdisp.fillCircle(100, 100, 50, 0xFFFFFFU);
    // sprite.setColorDepth(16);
    // sprite.createSprite(367, 400);
    // sprite.fillScreen(0xFFFFU);
    // sprite.pushSprite(&qdisp, 0, 0);
    // qdisp.display();

    // qdisp.setSwapBytes(true);
    // qdisp.pushImage(17, 35, 334, 334, (void *)gImage_cat24);
    // for (uint8_t i = 1; i < 150; i++)
    // {
    //     qdisp.setBrightness(i);
    //     vTaskDelay(10);
    // }
}

void HAL::amoled_PwmLightUp(uint8_t num)
{
    // qdisp.setSwapBytes(true);
    // qdisp.pushImage(17, 35, 334, 334, (void *)gImage_cat24);
    qdisp.startWrite();
    for (uint8_t i = 1; i < num; i++)
    {
        qdisp.setBrightness(i);
        vTaskDelay(10);
    }
    qdisp.endWrite();
}



/*********************************LovyanGFX Example************************************************/
LGFX_Sprite sprite(&amoled);
static LGFX_Sprite canvas(&amoled);
static LGFX_Sprite clockbase(&canvas); // 時計の文字盤パーツ
static LGFX_Sprite needle1(&canvas);   // 長針・短針パーツ
static LGFX_Sprite shadow1(&canvas);   // 長針・短針の影パーツ
static LGFX_Sprite needle2(&canvas);   // 秒針パーツ
static LGFX_Sprite shadow2(&canvas);   // 秒針の影パーツ

static constexpr uint64_t oneday = 86400000; // 1日 = 1000msec x 60sec x 60min x 24hour = 86400000
static uint64_t count = rand() % oneday;
static int32_t width = 239;
static int32_t halfwidth = width >> 1;
static float zoom;

void HAL::clock_test(void)
{
    amoled.init();
    amoled.setBrightness(150);

    zoom = (float)(std::min(amoled.width(), amoled.height())) / width;

    amoled.setPivot(amoled.width() >> 1, amoled.height() >> 1);

    canvas.setColorDepth(4); // 各部品を４ビットパレットモードで準備する
    clockbase.setColorDepth(4);
    needle1.setColorDepth(4);
    shadow1.setColorDepth(4);
    needle2.setColorDepth(4);
    shadow2.setColorDepth(4);

    canvas.createSprite(width, width); // メモリ確保
    clockbase.createSprite(width, width);
    needle1.createSprite(9, 119);
    shadow1.createSprite(9, 119);
    needle2.createSprite(3, 119);
    shadow2.createSprite(3, 119);

    // canvas.fillScreen(transpalette); // 透過色で背景を塗り潰す (create直後は0埋めされているので省略可能)
    // clockbase.fillScreen(transpalette);
    // needle1.fillScreen(transpalette);
    // shadow1.fillScreen(transpalette);

    clockbase.setTextFont(4); // フォント種類を変更(時計盤の文字用)
    clockbase.setTextDatum(lgfx::middle_center);
    clockbase.fillCircle(halfwidth, halfwidth, halfwidth, 6); // 時計盤の背景の円を塗る
    clockbase.drawCircle(halfwidth, halfwidth, halfwidth - 1, 15);

    for (int i = 1; i <= 60; ++i)
    {
        float rad = i * 6 * -0.0174532925; // 時計盤外周の目盛り座標を求める
        float cosy = -cos(rad) * (halfwidth * 10 / 11);
        float sinx = -sin(rad) * (halfwidth * 10 / 11);
        bool flg = 0 == (i % 5);                                                          // ５目盛り毎フラグ
        clockbase.fillCircle(halfwidth + sinx + 1, halfwidth + cosy + 1, flg * 3 + 1, 4); // 目盛りを描画
        clockbase.fillCircle(halfwidth + sinx, halfwidth + cosy, flg * 3 + 1, 12);
        if (flg)
        { // 文字描画
            cosy = -cos(rad) * (halfwidth * 10 / 13);
            sinx = -sin(rad) * (halfwidth * 10 / 13);
            clockbase.setTextColor(1);
            clockbase.drawNumber(i / 5, halfwidth + sinx + 1, halfwidth + cosy + 4);
            clockbase.setTextColor(15);
            clockbase.drawNumber(i / 5, halfwidth + sinx, halfwidth + cosy + 3);
        }
    }
    clockbase.setTextFont(7);

    needle1.setPivot(4, 100); // 針パーツの回転中心座標を設定する
    shadow1.setPivot(4, 100);
    needle2.setPivot(1, 100);
    shadow2.setPivot(1, 100);

    for (int i = 6; i >= 0; --i)
    { // 針パーツの画像を作成する
        needle1.fillTriangle(4, -16 - (i << 1), 8, needle1.height() - (i << 1), 0, needle1.height() - (i << 1), 15 - i);
        shadow1.fillTriangle(4, -16 - (i << 1), 8, shadow1.height() - (i << 1), 0, shadow1.height() - (i << 1), 1 + i);
    }
    for (int i = 0; i < 7; ++i)
    {
        needle1.fillTriangle(4, 16 + (i << 1), 8, needle1.height() + 32 + (i << 1), 0, needle1.height() + 32 + (i << 1), 15 - i);
        shadow1.fillTriangle(4, 16 + (i << 1), 8, shadow1.height() + 32 + (i << 1), 0, shadow1.height() + 32 + (i << 1), 1 + i);
    }
    needle1.fillTriangle(4, 32, 8, needle1.height() + 64, 0, needle1.height() + 64, 0);
    shadow1.fillTriangle(4, 32, 8, shadow1.height() + 64, 0, shadow1.height() + 64, 0);
    needle1.fillRect(0, 117, 9, 2, 15);
    shadow1.fillRect(0, 117, 9, 2, 1);
    needle1.drawFastHLine(1, 117, 7, 12);
    shadow1.drawFastHLine(1, 117, 7, 4);

    needle1.fillCircle(4, 100, 4, 15);
    shadow1.fillCircle(4, 100, 4, 1);
    needle1.drawCircle(4, 100, 4, 14);

    needle2.fillScreen(9);
    shadow2.fillScreen(3);
    needle2.drawFastVLine(1, 0, 119, 8);
    shadow2.drawFastVLine(1, 0, 119, 1);
    needle2.fillRect(0, 99, 3, 3, 8);

    amoled.startWrite();

    clockbase.pushSprite(&amoled, 0, 0);
    shadow1.pushSprite(&amoled, 100, 100); // デバッグ用、パーツを直接LCDに描画する
    needle1.pushSprite(&amoled, 150, 100);
    shadow2.pushSprite(&amoled, 200, 100);
    needle2.pushSprite(&amoled, 250, 100);
}

extern const unsigned short info[];
extern const unsigned short alert[];
extern const unsigned short closeX[];

static constexpr unsigned short infoWidth = 32;
static constexpr unsigned short infoHeight = 32;

static constexpr unsigned short alertWidth = 32;
static constexpr unsigned short alertHeight = 32;

static constexpr unsigned short closeWidth = 32;
static constexpr unsigned short closeHeight = 32;

static uint32_t sec, psec;
static size_t fps = 0, frame_count = 0;
static uint32_t lcd_width;
static uint32_t lcd_height;

struct obj_info_t
{
    int_fast16_t x;
    int_fast16_t y;
    int_fast16_t dx;
    int_fast16_t dy;
    int_fast8_t img;
    float r;
    float z;
    float dr;
    float dz;

    void move()
    {
        r += dr;
        x += dx;
        if (x < 0)
        {
            x = 0;
            if (dx < 0)
                dx = -dx;
        }
        else if (x >= lcd_width)
        {
            x = lcd_width - 1;
            if (dx > 0)
                dx = -dx;
        }
        y += dy;
        if (y < 0)
        {
            y = 0;
            if (dy < 0)
                dy = -dy;
        }
        else if (y >= lcd_height)
        {
            y = lcd_height - 1;
            if (dy > 0)
                dy = -dy;
        }
        z += dz;
        if (z < .5)
        {
            z = .5;
            if (dz < .0)
                dz = -dz;
        }
        else if (z >= 2.0)
        {
            z = 2.0;
            if (dz > .0)
                dz = -dz;
        }
    }
};

static constexpr size_t obj_count = 50;
static obj_info_t objects[obj_count];

static LGFX_Sprite sprites[2];
static LGFX_Sprite icons[3];
static int_fast16_t sprite_height;

void HAL::movingIcons(void)
{
    amoled.init();
    amoled.setColorDepth(16);
    // amoled.clear(0xFFFF);

    if (amoled.width() < amoled.height())
    {
        amoled.setRotation(amoled.getRotation() ^ 1);
    }
    lcd_width = 368;
    lcd_height = 448;
    obj_info_t *a;
    for (size_t i = 0; i < obj_count; ++i)
    {
        a = &objects[i];
        a->img = i % 3;
        a->x = rand() % lcd_width;
        a->y = rand() % lcd_height;
        a->dx = ((rand() & 3) + 1) * (i & 1 ? 1 : -1);
        a->dy = ((rand() & 3) + 1) * (i & 2 ? 1 : -1);
        a->dr = ((rand() & 3) + 1) * (i & 2 ? 1 : -1);
        a->r = 0;
        a->z = (float)((rand() % 10) + 10) / 10;
        a->dz = (float)((rand() % 10) + 1) / 100;
    }

    uint32_t div = 2;
    for (;;)
    {
        sprite_height = (lcd_height + div - 1) / div;
        bool fail = false;
        for (std::uint32_t i = 0; !fail && i < 2; ++i)
        {
            sprites[i].setColorDepth(16);
            sprites[i].setFont(&fonts::Font2);
            fail = !sprites[i].createSprite(lcd_width, sprite_height);
        }
        if (!fail)
            break;
        for (std::uint32_t i = 0; i < 2; ++i)
        {
            sprites[i].deleteSprite();
        }
        ++div;
    }

    icons[0].createSprite(infoWidth, infoHeight);
    icons[1].createSprite(alertWidth, alertHeight);
    icons[2].createSprite(closeWidth, closeHeight);

    icons[0].setSwapBytes(true);
    icons[1].setSwapBytes(true);
    icons[2].setSwapBytes(true);

    icons[0].pushImage(0, 0, infoWidth, infoHeight, info);
    icons[1].pushImage(0, 0, alertWidth, alertHeight, alert);
    icons[2].pushImage(0, 0, closeWidth, closeHeight, closeX);

    amoled.startWrite();

    while (1)
    {
        static uint8_t flip = 0;

        obj_info_t *a;
        for (int i = 0; i != obj_count; i++)
        {
            objects[i].move();
        }
        for (int_fast16_t y = 0; y < lcd_height; y += sprite_height)
        {
            flip = flip ? 0 : 1;
            sprites[flip].clear();
            for (size_t i = 0; i != obj_count; i++)
            {
                a = &objects[i];
                icons[a->img].pushRotateZoom(&sprites[flip], a->x, a->y - y, a->r, a->z, a->z, 0);
            }

            if (y == 0)
            {
                sprites[flip].setCursor(0, 0);
                sprites[flip].setFont(&fonts::Font4);
                sprites[flip].setTextColor(0xFFFFFFU);
                sprites[flip].printf("obj:%d  fps:%d", obj_count, fps);
            }
            sprites[flip].pushSprite(&amoled, 0, y);
        }
        amoled.display();

        ++frame_count;
        sec = lgfx::millis() / 1000;
        if (psec != sec)
        {
            psec = sec;
            fps = frame_count;
            frame_count = 0;
        }

        vTaskDelay(1);
    }
}









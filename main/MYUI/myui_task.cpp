#include "myui.h"
#include "BMI270.h"

static BMI270::BMI270 imu_for_task;

TaskHandle_t app_clock_Handle;
TaskHandle_t app_steps_Handle;

char hour_time[5];
char mins_time[5];
uint8_t hours = 10;
uint8_t mins = 10;

void MYUI::app_clock_task(void *params)
{
    while (1)
    {
        mins++;
        if (mins == 60)
        {
            mins = 0;
            hours++;
        }
        if (hours == 24)
        {
            hours = 0;
        }

        if (mins < 10 || hours < 10)
        {
            if (mins < 10)
            {
                sprintf(mins_time, "0%d", mins);
            }

            if (hours < 10)
            {
                sprintf(hour_time, "0%d", hours);
            }
        }
        else
        {
            sprintf(mins_time, "%d", mins);
            sprintf(hour_time, "%d", hours);
        }

        lv_label_set_text(app_clock_text_hour, hour_time);
        lv_label_set_text(app_clock_text_min, mins_time);
        vTaskDelay(60000);
    }
}


char steps[10];
void MYUI::app_steps_task(void *params)
{
    while (1)
    {
        sprintf(steps, "steps:%ld", imu_for_task.getSteps());
        lv_label_set_text(app_aniya_text, steps);
        vTaskDelay(1000*10);
    }
    
}



void MYUI::app_task_create(void)
{
    xTaskCreate(app_steps_task, "steps_task", 1024, NULL, 1, &app_steps_Handle);
}

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <freertos/event_groups.h>

TaskHandle_t temp_handle;
TaskHandle_t press_handle;
TaskHandle_t cali_handle;

EventGroupHandle_t sensor_eg;

const uint32_t temp_event_bit =(1<<0);
const uint32_t press_event_bit =(1<<1);
const uint32_t all_bit =(temp_event_bit|press_event_bit);

void TemperatureTask(void *pvParameters)
{
while(1)
{
    printf("Temperature Task\n");
    xEventGroupSetBits( sensor_eg,temp_event_bit);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}


void PressureTask(void *pvParameters)
{
while(1)
{
 printf("Pressure Task\n");
 xEventGroupSetBits( sensor_eg,press_event_bit);
 vTaskDelay(2000 / portTICK_PERIOD_MS);  
}
}

void CallibrationTask(void *pvParameters)
{
uint32_t result;
while(1)
{
 printf("Callibration Task\n");
 result= xEventGroupWaitBits(sensor_eg,all_bit,pdTRUE,pdTRUE,pdMS_TO_TICKS(5000));
 printf("RESULT = %d\n",result);
   
}
vTaskDelete(NULL);
}

void app_main()
{
    printf("Hello FREE RTOS\n");
    sensor_eg=xEventGroupCreate();
    xTaskCreate(TemperatureTask,"Task1",2048,NULL,5,&temp_handle);
    xTaskCreate(CallibrationTask,"Task3",2048,NULL,5,&cali_handle);
    xTaskCreate(PressureTask,"Task2",2048,NULL,5,&press_handle);
}

    

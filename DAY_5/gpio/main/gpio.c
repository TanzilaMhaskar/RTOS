#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define ALARM_PIN 15

void SensorTask(void *pvParameters)
{
while(1)
{
    printf("Sensor Task \n");
    vTaskDelay(1000 /portTICK_PERIOD_MS);
}

    
}
void AlarmTask(void *pvParameters)
{
    esp_rom_gpio_pad_select_gpio(ALARM_PIN);
    gpio_set_direction(ALARM_PIN,GPIO_MODE_OUTPUT);   
    while(1)
    {
    printf("Alarm Task\n");
    gpio_set_level(ALARM_PIN,0);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    gpio_set_level(ALARM_PIN,1);
}
}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(SensorTask,"Task1",1024,NULL,5,NULL);
    xTaskCreate(AlarmTask,"Task2",1024,NULL,5,NULL);
}
    

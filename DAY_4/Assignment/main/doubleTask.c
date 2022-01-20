#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask1;
TaskHandle_t xHandleTask2;
void Task1(void *pvParameters)
{
while(1)
{
    printf("Task1 \n");
}

    vTaskDelete(xHandleTask1);
}
void Task2(void *pvParameters)
{
while(1)
{
    printf("Task2 \n");
}

    vTaskDelete(xHandleTask2);
}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",1024,NULL,5,&xHandleTask1);
    xTaskCreate(Task2,"Task2",1024,NULL,10,&xHandleTask2);
}
    

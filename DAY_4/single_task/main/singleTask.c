#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask1;

void Task1(void *pvParameters)
{
    printf("Task \n");

    vTaskDelete(xHandleTask1);
}
void app_main()
{
    BaseType_t result;
    printf("Hello FREE RTOS\n");
    result =xTaskCreate(Task1,"Task1",1024,NULL,5,&xHandleTask1);
    if(result==pdPASS)
    {
        printf("Task Created\n");
    }


}
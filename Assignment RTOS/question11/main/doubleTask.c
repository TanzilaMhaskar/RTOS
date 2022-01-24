/*11. What is the API for deleting a task? Write a program demonstrate this capability.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask1;
TaskHandle_t xHandleTask2;
void Task1(void *pv)
{
while(1)
{
    printf("Task1 \n");
   vTaskDelay(500/portTICK_PERIOD_MS);
}
//api to delete the task
    vTaskDelete(xHandleTask1);
}
void Task2(void *pv)
{
while(1)
{
    printf("Task2 \n");
    vTaskDelay(500/portTICK_PERIOD_MS);
}

    vTaskDelete(xHandleTask2);
}
//main
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",1024,NULL,5,&xHandleTask1);
    xTaskCreate(Task2,"Task2",1024,NULL,5,&xHandleTask2);
}
    

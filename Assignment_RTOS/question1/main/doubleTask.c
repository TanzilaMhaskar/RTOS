/*1. Find what is the task priority numbering for the RTOS you are using. eg. Higher the
number higher the priority or vice-versa. Find the range of priority that can be assigned to
a task for your RTOS.*/


#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void Task1(void *pvParameters)
{
while(1)
{
    printf("Task1 \n");
    printf("Task1:%d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(1000 /portTICK_PERIOD_MS);
}

}
void Task2(void *pvParameters)
{
while(1)
{
    printf("Task2 \n");
    printf("Task2:%d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(1000 /portTICK_PERIOD_MS);
}

}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",2048,NULL,0,NULL);
    xTaskCreate(Task2,"Task2",2048,NULL,24,NULL);
}
   
 /* 
 MAX priority for task int this rtos is 24 */  

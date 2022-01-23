/* What is the mechanism used to make a task periodic for the RTOS you are using? Write a
program to make a task periodic with periodicity of 500ms.
ANS : Mechanism Used to make a task periodicity are vTaskDelay(1000 /portTICK_PERIOD_MS); . */

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void Task1(void *pvParameters)
{
while(1)
{
    printf("Task1 \n");
    printf("Task1:%d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(500/portTICK_PERIOD_MS);
}

}
void Task2(void *pvParameters)
{
while(1)
{
    printf("Task2 \n");
    printf("Task2:%d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(500/portTICK_PERIOD_MS);
}

}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",2048,NULL,5,NULL);
    xTaskCreate(Task2,"Task2",2048,NULL,5,NULL);
}
   
 /* 
 MAX priority for task int this rtos is 24 */  

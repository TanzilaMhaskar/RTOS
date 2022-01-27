/* Create two task with priority 10 and 20. Each task prints its own custom message */

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void Task1(void *pvParameters)
{
while(1)
{
    printf("Task1 \n");
    vTaskDelay(500/portTICK_PERIOD_MS);
}

}
void Task2(void *pvParameters)
{
while(1)
{
    printf("Task2 \n");
    vTaskDelay(500/portTICK_PERIOD_MS);
}

}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",2048,NULL,10,NULL);
    xTaskCreate(Task2,"Task2",2048,NULL,20,NULL);
}
   
 

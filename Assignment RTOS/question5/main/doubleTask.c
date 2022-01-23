/* Swap the priority and observe the changes in the output. What is your conclusion on the
sequence of printing the messages. */

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
    xTaskCreate(Task1,"Task1",2048,NULL,20,NULL); //SWAP prirotiy Task1= 10 to Task1=20
    xTaskCreate(Task2,"Task2",2048,NULL,10,NULL); //Task2=20 to Task2=10
}
   
 

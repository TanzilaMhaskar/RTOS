/*16. Write a RTOS application to demonstrate the use of changing priority*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask1;
TaskHandle_t xHandleTask2;
void Task1(void *pvParameters)
{
while(1)
{
    vTaskPrioritySet( xHandleTask1,2 );
    printf("Task1 priority:%d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(500/portTICK_PERIOD_MS);
    
}

}
void Task2(void *pvParameters)
{
while(1)
{
    printf("Task2:%d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(500/portTICK_PERIOD_MS);
}

}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",2048,NULL,5,&xHandleTask1);
    xTaskCreate(Task2,"Task2",2048,NULL,5,&xHandleTask2);
}
   
 /* 
 MAX priority for task int this rtos is 24 */  

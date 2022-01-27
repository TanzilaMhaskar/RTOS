/*15. Create a task to suspend itself after 1200 ms and resume it from another task */

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask1;
TaskHandle_t xHandleTask2;
void Task1(void *pvParameters)
{
while(1)
{
    printf("Task 1 suspend itself\n");
    vTaskDelay(pdMS_TO_TICKS(1200));
    vTaskSuspend(NULL);    //suspend call
    printf("Hi Task1 \n");
    
}
}

void Task2(void *pvParameters)
{
while(1)
{
    printf("Hi Task2 \n");
    vTaskDelay(pdMS_TO_TICKS(1000));
    printf("Task 2 Resume Task1\n");
    vTaskResume(xHandleTask1); //resume of task 1
    vTaskDelay(pdMS_TO_TICKS(1000));
    
    
}
    
}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",2500,NULL,5,&xHandleTask1);
    xTaskCreate(Task2,"Task2",2500,NULL,5,&xHandleTask2);
}
    

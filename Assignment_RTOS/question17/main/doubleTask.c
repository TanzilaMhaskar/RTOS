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
    vTaskDelay(500/portTICK_PERIOD_MS);
}

    vTaskDelete(xHandleTask1);
}
void Task2(void *pvParameters)
{
while(1)
{
    printf("Task2 \n");
    vTaskDelay(500/portTICK_PERIOD_MS);

}

    vTaskDelete(xHandleTask2);
}

void vApplicationIdleHook(void)
{
printf("This is idle HOOK function \n");
vTaskDelay(100);
}
void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",2048,NULL,5,&xHandleTask1);
    xTaskCreate(Task2,"Task2",2048,NULL,5,&xHandleTask2);
    vTaskStartScheduler();
}
    

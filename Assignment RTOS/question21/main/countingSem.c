/*Write a RTOS application to demonstrate counting semaphores to synchronize a task*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

static uint8_t data =0;
int semcount =0;

SemaphoreHandle_t CountingSem;

void SendingTask_1(void *pvParameters) //1st send data
{
    printf("Task 1\n");
    semcount=uxSemaphoreGetCount( CountingSem );
    printf("The Semaphore count =%d\n",semcount);
    while(1)
    {
    xSemaphoreGive(CountingSem);
    data ++;
    printf("data_1=%d\n",data);
    xSemaphoreTake(CountingSem,portMAX_DELAY);
    semcount=uxSemaphoreGetCount( CountingSem );
    printf("The Semaphore count =%d\n",semcount);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    
    }
}
void SendingTask_2(void *pvParameters)   //second send data
{
    printf("Task 2\n");
    
    while(1)
    {
     xSemaphoreGive(CountingSem);
    data ++;
    printf("data_2=%d\n",data);
    xSemaphoreTake(CountingSem,portMAX_DELAY);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}


void app_main()
{
    
    printf("Hello FREE RTOS\n");
    CountingSem = xSemaphoreCreateCounting(1,1);
    if( CountingSem != NULL )
    {
    printf("The Semaphore created");
    }
    xTaskCreate(SendingTask_1,"Sending Task",2500,NULL,5,NULL);
    xTaskCreate(SendingTask_2,"Sending Task",2500,NULL,5,NULL);
    
}
    

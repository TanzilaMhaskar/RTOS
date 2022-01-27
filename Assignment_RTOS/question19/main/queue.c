/*19. Write a RTOS application to demonstrate the effects of task priorities when sending to and
receiving from a queue.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>


QueueHandle_t sending_data;

void SendingTask_1(void *pvParameters) //1st send data
{
int data =0;
    while(1)
    {
    data ++;
    printf("Sensor data_1=%d\n",data);
    xQueueSend(sending_data,&data,portMAX_DELAY );
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void SendingTask_2(void *pvParameters)   //second send data
{
int data =10;
    while(1)
    {
    data ++;
    printf("Sensor data_2=%d\n",data);
    xQueueSend(sending_data,&data,portMAX_DELAY );
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void ProcessTask(void *pvParameters) //received task
{
    int receive_data=0;
    while(1)
    {
    xQueueReceive(sending_data, &receive_data,portMAX_DELAY );
    printf("Process Task Receive =%d\n",receive_data);
    }
}
void app_main()
{
    
    printf("Hello FREE RTOS\n");
    sending_data= xQueueCreate(10,sizeof(int));
    xTaskCreate(SendingTask_1,"SensorTask",2500,NULL,5,NULL);
    xTaskCreate(ProcessTask,"ProcessTask",2500,NULL,3,NULL);
    xTaskCreate(SendingTask_2,"SensorTask",2500,NULL,7,NULL);
    
}
    

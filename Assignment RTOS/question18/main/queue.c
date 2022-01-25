/*Write a RTOS application to demonstrate the use of task to task communication using
Queue management APIs. Also demonstrate blocking on a queue.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>


QueueHandle_t sensor_queue;
TaskHandle_t  sensor,process;

void SensorTask(void *pvParameters)
{
int sensor_data =0;
    while(1)
    {
    sensor_data ++;
    printf("Sensor data=%d\n",sensor_data);
    xQueueSend(sensor_queue,&sensor_data,portMAX_DELAY);
    vTaskSuspend(sensor);//blocking sending till it send all data
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void ProcessTask(void *pvParameters)
{
    int receive_data=0;
    while(1)
    {
    vTaskResume(sensor);
    xQueueReceive(sensor_queue, &receive_data,portMAX_DELAY);
    printf("Process Task Receive =%d\n",receive_data);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    
    printf("Hello FREE RTOS\n");
    sensor_queue = xQueueCreate(10,sizeof(int));
    xTaskCreate(SensorTask,"SensorTask",2500,NULL,5,&sensor);
    xTaskCreate(ProcessTask,"ProcessTask",2500,NULL,3,&process);
}
    

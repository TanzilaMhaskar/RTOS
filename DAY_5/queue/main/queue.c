#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>


QueueHandle_t sensor_queue;

void SensorTask(void *pvParameters)
{
int sensor_data =0;
    while(1)
    {
    sensor_data ++;
    printf("Sensor data=%d\n",sensor_data);
    xQueueSend(sensor_queue,&sensor_data,portMAX_DELAY );
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void ProcessTask(void *pvParameters)
{
    int receive_data=0;
    while(1)
    {
    xQueueReceive(sensor_queue, &receive_data,portMAX_DELAY );
    printf("Process Task Receive =%d\n",receive_data);
    }
}
void app_main()
{
    
    printf("Hello FREE RTOS\n");
    sensor_queue = xQueueCreate(10,sizeof(int));
    xTaskCreate(SensorTask,"SensorTask",2500,NULL,5,NULL);
    xTaskCreate(ProcessTask,"ProcessTask",2500,NULL,3,NULL);
}
    

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


TaskHandle_t sensorHandle;
TaskHandle_t processHandle;

void SensorTask(void *pvParameters)
{
int sensor_data =0;
    while(1)
    {
    sensor_data ++;
    printf("Sensor data=%d\n",sensor_data);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    if (sensor_data ==10)
    {
    vTaskResume(processHandle);
    printf("Sensor data=%d\n",sensor_data);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
    }
}

void ProcessTask(void *pvParameters)
{
    int receive_data=0;
    while(1)
    {
    vTaskSuspend(NULL);
    printf("Process Task Receive =%d\n",receive_data);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    
    printf("Hello FREE RTOS\n");
    xTaskCreate(SensorTask,"SensorTask",2500,NULL,5,&sensorHandle);
    xTaskCreate(ProcessTask,"ProcessTask",2500,NULL,3,&processHandle);
    
}
    

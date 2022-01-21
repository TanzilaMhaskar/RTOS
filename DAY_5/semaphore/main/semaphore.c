#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>


SemaphoreHandle_t sem;
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
    xSemaphoreGive(sem);
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
    xSemaphoreTake(sem ,portMAX_DELAY);
    printf("Process Task Receive =%d\n",receive_data);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
void app_main()
{
    
    printf("Hello FREE RTOS\n");
    sem=xSemaphoreCreateBinary();
    xTaskCreate(SensorTask,"SensorTask",2500,NULL,5,NULL);
    xTaskCreate(ProcessTask,"ProcessTask",2500,NULL,3,NULL);
    xSemaphoreTake(sem,portMAX_DELAY);
}
    

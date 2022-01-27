/*3. Find the APIs in your RTOS that provides timestamp and use it to print the periodic task.
Observe the jitter in the timestamp vs the periodicity. Enhance the code to 10 periodic tasks
with different periodicity. Futher observe the jitter in each of the task.*/

// i have created 5 priodic task
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void Task1(void *pvParameters)
{
while(1)
{
    TickType_t count=0;
    printf("Task1 \n");
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
    vTaskDelay(1000 /portTICK_PERIOD_MS);
    count=xTaskGetTickCount();
    printf("TIck count =%d\n",count);
}

}
void Task2(void *pvParameters)
{
while(1)
{
    TickType_t count=0;
    printf("Task2 \n");
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
    vTaskDelay(2000 /portTICK_PERIOD_MS);
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
}
}
void Task3(void *pvParameters)
{
while(1)
{
    TickType_t count=0;
    printf("Task3 \n");
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
    vTaskDelay(3000 /portTICK_PERIOD_MS);
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
}

}
void Task4(void *pvParameters)
{
while(1)
{
    TickType_t count=0;
    printf("Task4\n");
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
    vTaskDelay(4000 /portTICK_PERIOD_MS);
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
}
}
void Task5(void *pvParameters)
{
while(1)
{
   TickType_t count=0;
    printf("Task5\n");
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
    vTaskDelay(5000/portTICK_PERIOD_MS);
    count=xTaskGetTickCount();
    printf("Tick count =%d\n",count);
}
}

void app_main()
{
    printf("Hello FREE RTOS\n");
    xTaskCreate(Task1,"Task1",2048,NULL,5,NULL);
    xTaskCreate(Task2,"Task2",2048,NULL,5,NULL);
    xTaskCreate(Task3,"Task3",2048,NULL,5,NULL);
    xTaskCreate(Task4,"Task4",2048,NULL,5,NULL);
    xTaskCreate(Task5,"Task5",2048,NULL,5,NULL);
    //xTaskCreate(Task6,"Task6",2048,NULL,5,NULL);
}
  

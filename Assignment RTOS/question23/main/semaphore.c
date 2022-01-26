/*23. Write a RTOS application to manage resources using mutual exclusion*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>


SemaphoreHandle_t mutex_v;

void Task1(void *pvParameters) 
{ 
while(1) 
{ 
xSemaphoreTake(mutex_v, portMAX_DELAY); //mutex blocked
printf("Hi from Task1\n"); 
xSemaphoreGive(mutex_v);        //unblocked
vTaskDelay(pdMS_TO_TICKS(1000)); 
} 
}


void Task2(void *pvParameters) 
{ 
while(1) 
{ 
xSemaphoreTake(mutex_v, portMAX_DELAY); //blocked
printf("Hi from Task2\n"); 
xSemaphoreGive(mutex_v);  //unblocked
vTaskDelay(pdMS_TO_TICKS(1000)); 
} 
}
void app_main()
{
    
    printf("Hello FREE RTOS\n");
    mutex_v = xSemaphoreCreateMutex(); 
   if (mutex_v == NULL) 
   { 
    printf("Mutex can not be created"); 
    } 
    xTaskCreate(Task1,"TASK_1",2048,NULL,5,NULL);
    xTaskCreate(Task2,"TASK_2",2048,NULL,5,NULL);
  
}
    

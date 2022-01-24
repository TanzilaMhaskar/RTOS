/*25. Write a RTOS application to create a software timer that invokes a callback function every
5 seconds*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>

TimerHandle_t motor_timer_handle;


void TurnMotorOFF(TimerHandle_t xTimer) //callback every 1sec
{
printf("Turning motor off\n");
}

void  app_main()
{
    printf("Hello Free RTOS\n");
    motor_timer_handle= xTimerCreate("MotorOFF",pdMS_TO_TICKS(1000),pdTRUE,NULL,TurnMotorOFF); //create timer
    
    xTimerStart(motor_timer_handle,0);
    while(1)
    {
    printf("Main Task\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
}

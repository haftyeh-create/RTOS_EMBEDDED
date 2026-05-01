#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <avr/io.h>

/* Basic FreeRTOS configuration for ATmega32 */
#define configUSE_PREEMPTION                1
#define configUSE_IDLE_HOOK                 0
#define configUSE_TICK_HOOK                 0
#define configCPU_CLOCK_HZ                  ( ( unsigned long ) 8000000 )
#define configTICK_RATE_HZ                  ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES                4
#define configMINIMAL_STACK_SIZE            ( ( unsigned short ) 85 )
#define configTOTAL_HEAP_SIZE               ( ( size_t ) 1500 )
#define configMAX_TASK_NAME_LEN             8
#define configUSE_TRACE_FACILITY            0
#define configUSE_16_BIT_TICKS              1
#define configIDLE_SHOULD_YIELD             1
#define configUSE_MUTEXES                   0
#define configUSE_RECURSIVE_MUTEXES         0
#define configUSE_COUNTING_SEMAPHORES       0
#define configQUEUE_REGISTRY_SIZE           0
#define configUSE_TIMERS                    0
#define configUSE_CO_ROUTINES               0
#define configMAX_CO_ROUTINE_PRIORITIES     2
#define configSUPPORT_DYNAMIC_ALLOCATION    1
#define configSUPPORT_STATIC_ALLOCATION     0

/* Include/exclude FreeRTOS API functions */
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_vTaskDelayUntil             1

#endif /* FREERTOS_CONFIG_H */

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"

/* Pin Definitions */
#define GREEN_LED_PIN    PB0
#define YELLOW_LED_PIN   PB1
#define RED_LED_PIN      PB2

/* Task Priorities */
#define GREEN_TASK_PRIORITY    3    /* Highest */
#define YELLOW_TASK_PRIORITY   2    /* Medium  */
#define RED_TASK_PRIORITY      1    /* Lowest  */

#define TASK_STACK_SIZE    configMINIMAL_STACK_SIZE

/* Task Prototypes */
void vGreenLEDTask(void *pvParameters);
void vYellowLEDTask(void *pvParameters);
void vRedLEDTask(void *pvParameters);

void hardware_init(void)
{
	DDRB  |= (1 << GREEN_LED_PIN) | (1 << YELLOW_LED_PIN) | (1 << RED_LED_PIN);
	PORTB &= ~((1 << GREEN_LED_PIN) | (1 << YELLOW_LED_PIN) | (1 << RED_LED_PIN));
}

int main(void)
{
	hardware_init();

	xTaskCreate(vGreenLEDTask,  "GreenLED",  TASK_STACK_SIZE, NULL, GREEN_TASK_PRIORITY,  NULL);
	xTaskCreate(vYellowLEDTask, "YellowLED", TASK_STACK_SIZE, NULL, YELLOW_TASK_PRIORITY, NULL);
	xTaskCreate(vRedLEDTask,    "RedLED",    TASK_STACK_SIZE, NULL, RED_TASK_PRIORITY,    NULL);

	vTaskStartScheduler();

	while(1);
	return 0;
}

/* Green LED - HIGHEST Priority - blinks fast 200ms */
void vGreenLEDTask(void *pvParameters)
{
	(void)pvParameters;
	for(;;)
	{
		PORTB |=  (1 << GREEN_LED_PIN);
		vTaskDelay(pdMS_TO_TICKS(200));
		PORTB &= ~(1 << GREEN_LED_PIN);
		vTaskDelay(pdMS_TO_TICKS(200));
	}
}

/* Yellow LED - MEDIUM Priority - blinks 500ms */
void vYellowLEDTask(void *pvParameters)
{
	(void)pvParameters;
	for(;;)
	{
		PORTB |=  (1 << YELLOW_LED_PIN);
		vTaskDelay(pdMS_TO_TICKS(500));
		PORTB &= ~(1 << YELLOW_LED_PIN);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

/* Red LED - LOWEST Priority - blinks slow 1000ms */
void vRedLEDTask(void *pvParameters)
{
	(void)pvParameters;
	for(;;)
	{
		PORTB |=  (1 << RED_LED_PIN);
		vTaskDelay(pdMS_TO_TICKS(1000));
		PORTB &= ~(1 << RED_LED_PIN);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

#include <FreeRTOS.h>
#include <timers.h>
#include <task.h>

#include "leds.h"

void blinky_task(void *params)
{
	(void)params;

	/* 250Ms delay */
	const portTickType heartbeat_delay = 250 / portTICK_RATE_MS;

	uint8_t led_num = 0;

	/* Initialize the LED driver */
	led_init();

	/* Turn off all of the LEDs */
	for (int i = 0; i < 4; i++) {
		led_clear(i);
	}

	while(1){
		led_toggle(0);

		/* Pause for a bit before moving on */
		vTaskDelay(heartbeat_delay);
	}
}

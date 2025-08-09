#include<stdio.h>
#include "led.h"
#include "../Logging/logging.h"
#include "../HAL/gpio.h"

void Led_Init(void)
{
    // Initialize the LEDs
    GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);
    GPIO_Init(LED_YELLOW_PORT, LED_YELLOW_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);
    GPIO_Init(LED_RED_PORT, LED_RED_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);

    // Log Initialization
    Logging_Send(LOG_LED_INIT);
}
void Led_UpdateState(Led_State_t state)
{
    // Simulate LED state update
    printf("Updating LED states...\n");

    switch(state)
    {
        case LED_NORMAL:
            printf("LED State: NORMAL\n");
            // Set Green LEDs to normal state
            GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);
            GPIO(LED_YELLOW_PORT, LED_YELLOW_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_RED_PORT, LED_RED_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            break;
        case LED_WATERING:
            printf("LED State: WATERING\n");
            // Set Yellow LED on, others off
            GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_YELLOW_PORT, LED_YELLOW_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);
            GPIO_Init(LED_RED_PORT, LED_RED_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            break;
        case LED_LOW_MOISTURE_ALERT:
            printf("LED State: LOW MOISTURE ALERT\n");
            // Set Red LED on, others off
            GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_YELLOW_PORT, LED_YELLOW_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_RED_PORT, LED_RED_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);
            break;
        case LED_ERROR:
            printf("LED State: ERROR\n");
            // Set all LEDs off
            GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_YELLOW_PORT, LED_YELLOW_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_RED_PORT, LED_RED_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            break;
        default:
            printf("LED State: UNKNOWN\n");
            // Default case, turn off all LEDs
            GPIO_Init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_YELLOW_PORT, LED_YELLOW_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            GPIO_Init(LED_RED_PORT, LED_RED_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
            break;
    }
}
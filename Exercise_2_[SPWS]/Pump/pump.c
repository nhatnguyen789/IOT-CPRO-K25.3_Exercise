#include<stdio.h>
#include "pump.h"
#include "../Logging/logging.h"
#include "../HAL/gpio.h"

// Global variable to track pump state
Pump_State_t pump_state = PUMP_OFF;

void Pump_Init(void)
{
    // Initialize the pump
    GPIO_Init(PUMP_PORT, PUMP_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);

    // log Initialization
    Logging_LogMessage("PUMP: module initialized - Pump: %c%d\n", PUMP_PORT, PUMP_PIN);
    Pump_Off(); // Ensure pump is off after initialization
}
void Pump_On(void)
{
    if(pump_state == PUMP_OFF)
    {
        GPIO_Init(PUMP_PORT, PUMP_PIN, GPIO_MODE_OUPUT_PP, GPIO_PULL_NONE);
        printf("Pump is now ON.\n");
        pump_state = PUMP_ON;
    }
}
void Pump_Off(void)
{
    if(pump_state == PUMP_ON)
    {
        GPIO_Init(PUMP_PORT, PUMP_PIN, GPIO_MODE_INPUT, GPIO_PULL_NONE);
        printf("Pump is now OFF.\n");
        pump_state = PUMP_OFF;
    }
}

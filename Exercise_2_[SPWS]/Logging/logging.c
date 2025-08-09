#include<stdio.h>
#include "logging.h"
#include "../HAL/gpio.h"

void Logging_Init(void)
{
    // In a real project, we would initialize a UART port or other
    // communication peripherals here.
    printf("[LOG]: Logging module initialized.\n");
}

void Logging_Send(LogCode_t code)
{
    switch(code)
    {
        case LOG_SYSTEM_INIT:
            printf("[LOG]: System initialized.\n");
            break;
        case LOG_PUMP_ON:
            printf("[LOG]: Pump activated.\n");
            break;
        case LOG_PUMP_OFF:
            printf("[LOG]: Pump deactivated.\n");
            break;
        case LOG_MODE_AUTO:
            printf("[LOG]: Switched to AUTO mode.\n");
            break;
        case LOG_MOPDE_MANUAL:
            printf("[LOG]: Switched to MANUAL mode.\n");
            break;
        case LOG_WATERING_STARTED:
            printf("[LOG]: Starting automatic process.\n");
            break;
        case LOG_WATERING_STOPPED:
            printf("[LOG]: Stopping automatic process.\n");
            break;
        case LOG_LOW_MOISTURE_ALERT:
            printf("[LOG]: Low moisture alert! Checking conditions for watering.\n");
            break;
        case LOG_MANUAL_WATERING_STARTED:
            printf("[LOG]: Starting manual watering.\n");
            break;
        case LOG_MANUAL_WATERING_STOPPED:
            printf("[LOG]: Stopping manual watering.\n");
            break;
        case LOG_BUTTON_INIT:
            printf("[LOG]: Button module initialized.\n");
            break;
        case LOG_BUTTON_AUTOMATIC:
            printf("[LOG]: Button pressed for automatic mode.\n");
            break;
        case LOG_BUTTON_MANUAL:
            printf("[LOG]: Button pressed for manual mode.\n");
            break;
        case LOG_UNKNOWN:
            printf("[LOG]: Unknown log code received.\n");
            break;
        case LOG_ERROR:
            printf("[LOG]: An error occurred in the system.\n");
            break;
        case LOG_LED_STATE_UPDATE:
            printf("[LOG]: LED state updated.\n");
            break;
        case LOG_LED_INIT:
            printf("[LOG]: LED module initialized.\n");
            break;
        case LOG_PUMP_INIT:
            printf("[LOG]: Pump module initialized.\n");
            break;
        case LOG_PUMP_STATE_UPDATE:
            printf("[LOG]: Pump state updated.\n");
            break;
        case LOG_ACTUATOR_ERROR:
            printf("[LOG]: Actuator error occurred.\n");
            break;
        case LOG_SENSOR_ERROR:
            printf("[LOG]: Sensor error occurred.\n");
            break;
        case LOG_SYSTEM_ERROR:
            printf("[LOG]: System error occurred.\n");
            break;
        case LOG_USER_ACTION:
            printf("[LOG]: User action logged.\n"); 
            break;
        default:
            printf("[LOG]: Unknown log code: %d\n", code);
            break;
    }
}
void Logging_SendWithData(LogCode_t code, const char *data_str)
{
    // This function sends a log message with additional data
    switch(code)
    {
        case LOG_SENSOR_READING:
            printf("[LOG]: Sensor reading: %s\n", data_str);
            break;
        case LOG_DATA_RECEIVED:
            printf("[LOG]: Data received: %s\n", data_str);
            break;
        case LOG_DATA_SENT:
            printf("[LOG]: Data sent: %s\n", data_str);
            break;
        case LOG_DATA_PROCESSING:
            printf("[LOG]: Data processing: %s\n", data_str);
            break;
        case LOG_DATA_STORAGE:
            printf("[LOG]: Data storage: %s\n", data_str);
            break;
        case LOG_DATA_RETRIEVAL:
            printf("[LOG]: Data retrieval: %s\n", data_str);
            break;
        default:
            printf("[LOG]: Unknown log code with data: %d, Data: %s\n", code, data_str);
            break;
    }
}
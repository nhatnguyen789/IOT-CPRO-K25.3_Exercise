#ifndef __LOGGING_H__
#define __LOGGING_H__


// include header files

// Constant

//  ---Data type---
// Using enums to define log messages to save Flash memory, as requested.
// Each enum value corresponds to a specific log message.
typedef enum
{
    LOG_SYSTEM_INIT,
    LOG_PUMP_ON,
    LOG_PUMP_OFF,
    LOG_MODE_AUTO,
    LOG_MOPDE_MANUAL,
    LOG_WATERING_STARTED,
    LOG_WATERING_STOPPED,
    LOG_LOW_MOISTURE_ALERT,
    LOG_MANUAL_WATERING_STARTED,
    LOG_MANUAL_WATERING_STOPPED,
    LOG_SENSOR_READING,
    LOG_BUTTON_INIT, // For button initialization
    LOG_BUTTON_AUTOMATIC, // For button automatic mode
    LOG_BUTTON_MANUAL, // For button manual mode
    LOG_UNKNOWN, // For any unknown log codes
    LOG_ERROR,  // For error logging
    LOG_LED_STATE_UPDATE, // For LED state updates
    LOG_LED_INIT, // For LED initialization
    LOG_PUMP_INIT, // For pump initialization
    LOG_PUMP_STATE_UPDATE, // For pump state updates
    LOG_ACTUATOR_ERROR, // For actuator errors
    LOG_SENSOR_ERROR, // For sensor errors
    LOG_SYSTEM_ERROR, // For system errors
    LOG_USER_ACTION, // For user actions
    LOG_DATA_RECEIVED, // For data received from sensors or user input
    LOG_DATA_SENT, // For data sent to actuators or other systems
    LOG_DATA_PROCESSING, // For data processing events
    LOG_DATA_STORAGE, // For data storage events
    LOG_DATA_RETRIEVAL, // For data retrieval eventS
}LogCode_t;

// Function prototype
void Logging_Init(void);
//void Logging_LogMessage(const char *format, ...);
void Logging_Send(LogCode_t code);
void Logging_SendWithData(LogCode_t code, const char *data_str);

#endif // __LOGGING_H__


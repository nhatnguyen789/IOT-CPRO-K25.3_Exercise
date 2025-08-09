
#ifndef __CONFIG_H__
#define __CONFIG_H__


// include header files

// Constant

//  Data type
typedef enum 
{
    MODE_AUTO,
    MODE_MANUAL,
}System_Mode_t;

// Setting System
typedef struct 
{
    int min_moisture_threshold; // Minimum moisture level to trigger watering
    int max_moisture_threshold; // Maximum moisture level to stop watering
    int max_watering_time_s; // Maximum time to water in seconds
    int sensor_check_interval_s; // Interval to check sensor in seconds
    System_Mode_t current_mode; // Current system mode (AUTO or MANUAL)
}System_Config_t;

// Function prototype

//---global variables externs---
extern System_Config_t system_settings;


#endif // __CONFIG_H__


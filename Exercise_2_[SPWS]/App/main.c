// include header files
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "../App/config.h"
#include "../Button/button.h"
#include "../Sensor/sensor.h"
#include "../Led/led.h"
#include "../Pump/pump.h"
#include "../Logging/logging.h"

// externs for global variables
extern Pump_State_t pump_state;

// global constants
#define MINIMUM_MOISTURE_LEVEL 40 // Minimum moisture level to trigger watering
#define MAXIMUM_MOISTURE_LEVEL 70 // Maximum moisture level to stop watering

//global data type

// global variables
Sensor_Data_t sensor_value;
System_Config_t system_settings;   

// Variables managing time based events
clock_t last_sensor_check_time;
clock_t pump_start_time;

// local function prototype
static void log_sensor_data(void)
{
    char log_buffer[64];
    sprintf(log_buffer, "Temperature: %.2fC, Humidity: %d%%", sensor_value.Temperature, sensor_value.Humidity);
    Logging_SendWithData(LOG_SENSOR_READING, log_buffer);
}

//Helper function to handle button presses
static void handle_button_press(Button_t button)
{
    if(button == BUTTON_MODE_TOGGLE)
    {
        if(system_settings.current_mode == MODE_AUTO)
        {
            system_settings.current_mode = MODE_MANUAL;
            Pump_Off(); // Turn off pump in manual mode
            Logging_Send(LOG_MOPDE_MANUAL);
        }
        else
        {
            system_settings.current_mode = MODE_AUTO;
            Logging_Send(LOG_MODE_AUTO);
        }
    }
    else if(button == BUTTON_MANUAL_WATER)
    {
        if(system_settings.current_mode == MODE_MANUAL)
        {
            Logging_Send(LOG_MANUAL_WATERING_STARTED);
            Pump_On(); // Turn on pump for manual watering
            pump_start_time = clock(); // Record the time when manual watering started
        }
    }
}
static void main_init(void)
{
    //1. Initialize all modules
    Led_Init(); // Initialize LED module
    Pump_Init(); // Initialize Pump module
    Logging_Init(); // Initialize logging module
    Sensor_Init(); // Initialize Sensor module
    Button_Init(); // Initialize Button module

    //2. Set default system configuration
    system_settings.min_moisture_threshold = MINIMUM_MOISTURE_LEVEL;
    system_settings.max_moisture_threshold = MAXIMUM_MOISTURE_LEVEL;
    system_settings.max_watering_time_s = 60; // Set maximum watering time to 60 seconds
    system_settings.sensor_check_interval_s = 5; // Set sensor check interval to 5 seconds
    system_settings.current_mode = MODE_AUTO; // Set initial mode to AUTO

    //3. Set initial state
    last_sensor_check_time = clock() - (system_settings.sensor_check_interval_s * CLOCKS_PER_SEC); // Initialize last sensor check time to allow immediate sensor reading
    pump_start_time = 0; // Initialize pump start time to 0
    Led_UpdateState(LED_NORMAL); // Set initial LED state to NORMAL
    Logging_Send(LOG_SYSTEM_INIT); // Log system initialization

}
// global function definition
int main(void)
{
    main_init(); 
    while(1)
    {
        // 1. Hanlde button presses
        Button_t button_pressed = Button_CheckState();
        if(button_pressed != BUTTON_NONE)
        {
            handle_button_press(button_pressed);
        }

        //2. Main logic for automactic watering system
        if(system_settings.current_mode == MODE_AUTO)
        {
            // Check if it's time to read senser values
            if((clock() - last_sensor_check_time) / CLOCKS_PER_SEC >= system_settings.sensor_check_interval_s )
            {
                Sensor_ReadValues();
                log_sensor_data(); // Log sensor data
                last_sensor_check_time = clock(); // Update last sensor check time

                // Check if moisture is too low and watering is needed
                if(sensor_value.Humidity < system_settings.min_moisture_threshold)
                {
                    if(pump_state == PUMP_OFF)
                    {
                        Logging_Send(LOG_LOW_MOISTURE_ALERT);
                        Logging_Send(LOG_WATERING_STARTED);
                        Pump_On(); // Turn on pump for watering
                        Led_UpdateState(LED_WATERING); // Update LED state to WATERING
                        pump_start_time = clock();
                    }
                }
            }

            //If pump is on, check for conditions to turn it off
            if(pump_state == PUMP_ON)
            {
                // Check if max moisture is reached or max watering time is exceeded
                if(sensor_value.Humidity >= system_settings.max_moisture_threshold ||
                (clock() - pump_start_time) / CLOCKS_PER_SEC >= system_settings.max_watering_time_s)
                {
                    Logging_Send(LOG_WATERING_STOPPED);
                    Pump_Off();
                    Led_UpdateState(LED_NORMAL); // Update LED state to NORMAL
                }
            }
        }
        //logic for manual watering
        else if(system_settings.current_mode == MODE_MANUAL)
        {
            // if manual watring is active, check the duration
            if(pump_state == PUMP_ON && 
               (clock() - pump_start_time) / CLOCKS_PER_SEC >= MANUAL_WATERING_DURATION_S)
            {
                Logging_Send(LOG_MANUAL_WATERING_STOPPED);
                Pump_Off(); // Turn off pump after manual watering duration
                Led_UpdateState(LED_NORMAL); // Update LED state to NORMAL
            }
        }
        usleep(100000); 
    }

    return 0;
}



// include header files
#include <stdio.h>
#include "sensor.h"
#include "../HAL/gpio.h"
#include "../Logging/logging.h"

// global constants


//global data type


// global variables
static Sensor_Data_t g_sensor_data;

// global function prototype

// global function definition
void Sensor_Init(void)
{
    GPIO_Init(SENSOR_HUMIDITY_PORT, SENSOR_HUMIDITY_PIN, GPIO_MODE_ANALOG, GPIO_PULL_NONE);
    GPIO_Init(SENSOR_TEMPRTATURE_PORT, SENSOR_TEMPERATURE_PIN, GPIO_MODE_ANALOG, GPIO_PULL_NONE);
    // Log Initialization
    printf("SENSOR: module initialized - Humidity: %c%d, Temperature: %c%d\n", 
           SENSOR_HUMIDITY_PORT, SENSOR_HUMIDITY_PIN, 
           SENSOR_TEMPRTATURE_PORT, SENSOR_TEMPERATURE_PIN);

    // Initialize with some default values.
    g_sensor_data.Humidity = 0;
    g_sensor_data.Temperature = 0.0f;
}
void Sensor_ReadValues(void)
{
    printf("---SIMULATED SENSOR READINGS---\n");

    printf("\nInput Humiditty (0-100): ");
    scanf("%d", &g_sensor_data.Humidity);

    printf("\nInput Temperature (Celsius):");
    scanf("%f", &g_sensor_data.Temperature);
    printf("------------------------------\n");
}
void Sensor_GetData(Sensor_Data_t *pData)
{
    if(pData != NULL)
    {
        pData->Humidity = g_sensor_data.Humidity;
        pData->Temperature = g_sensor_data.Temperature;

        //log the sensor data
        printf("SENSOR: Humidity = %d, Temperature = %.2f\n", pData->Humidity, pData->Temperature);
    }
    else
    {
        printf("SENSOR: Error - Null pointer passed to Sensor_GetData\n)");
    }
}
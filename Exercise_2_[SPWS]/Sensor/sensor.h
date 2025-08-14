#ifndef __SENSOR_H__
#define __SENSOR_H__




// include header files


// Constant
//---SENSOR CONFIGURATION---
#define SENSOR_HUMIDITY_PORT    'A'
#define SENSOR_HUMIDITY_PIN    0    // PA0 -> ADC_IN0

#define SENSOR_TEMPRTATURE_PORT    'A'
#define SENSOR_TEMPERATURE_PIN    1    // PA1 -> ADC_IN1


//  Data type
typedef struct
{
    int Humidity;
    float Temperature;
}Sensor_Data_t;


// Function prototype
void Sensor_Init(void);
Sensor_Data_t Sensor_ReadValues(void);
void Sensor_GetData(Sensor_Data_t *pData);

// externs for global variables
extern Sensor_Data_t sensor_data; 

#endif // __SENSOR_H__


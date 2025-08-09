#ifndef __PUMP_H__
#define __PUMP_H__


// include header files


// Constant
//---ACTUATOR CONFIGURATION---
#define PUMP_PORT    'B'
#define PUMP_PIN   0    // PB0 -> GPIO_OUT

// constants for manual watering
#define MANUAL_WATERING_DURATION_S 10

//  Data type
typedef enum
{
    PUMP_OFF,  // Pump is off
    PUMP_ON,   // Pump is on
}Pump_State_t;

// Function prototype
void Pump_Init(void);
void Pump_On(void);
void Pump_Off(void);

#endif // __PUMP_H__


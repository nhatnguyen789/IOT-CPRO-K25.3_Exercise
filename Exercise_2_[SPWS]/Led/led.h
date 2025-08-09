#ifndef __LED_H__
#define __LED_H__


// include header files


// Constant
// ---LED CONFIGURATION---
#define LED_GREEN_PORT   'B'
#define LED_GREEN_PIN    5    // PB1 -> GPIO_OUT

#define LED_YELLOW_PORT     'B'
#define LED_YELLOW_PIN   6    // PB2 -> GPIO_OUT

#define LED_RED_PORT   'B'
#define LED_RED_PIN    7    // PB3 -> GPIO_OUT

//  Data type
typedef enum
{
    LED_NORMAL,  // Normal state
    LED_WATERING, // Watering state
    LED_LOW_MOISTURE_ALERT, // Low moisture alert state
    LED_ERROR, // Error state
}Led_State_t;


// Function prototype
void Led_Init(void);
void Led_UpdateState(Led_State_t state);


#endif // __LED_H__


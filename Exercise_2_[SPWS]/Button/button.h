#ifndef __BUTTON_H__
#define __BUTTON_H__

// include header files
#include <stdbool.h>
// Constant
//---BUTTON CONFIGURATION---
#define BUTTON_TOGGLE_MODE_PORT   'C'
#define BUTTON_TOGGLE_MODE_PIN   13    // PC0 -> GPIO_IN

#define BUTTON_MANUAL_WATER_PORT  'A'
#define BUTTON_MANUAL_WATER_PIN   8    // PC1 -> GPIO_IN

//  Data type
typedef enum
{
    BUTTON_MODE_TOGGLE,  // Toggle mode button
    BUTTON_MANUAL_WATER,  // Manual mode button
    BUTTON_NONE,
}Button_t;

// Function prototype
void Button_Init(void);
void Button_Scan(void);
Button_t Button_CheckState(void);
bool Button_IsToggleModePresed(void);
bool Button_IsManualWaterPresed(void);


#endif // __BUTTON_H__


#ifndef __GPIO_H__
#define __GPIO_H__

// include header files

// Constant


//  Data type
//---ENUM SIMULATE GPIO MODE ON STM32--- 
typedef enum
{
    GPIO_MODE_INPUT,
    GPIO_MODE_OUPUT_PP, // Push-Pull Output
    GPIO_MODE_ANALOG,   
}GPIO_Mode_t;

//---ENUM SIMULATE PULL UP REGISTER ON STM32---
typedef enum
{
    GPIO_PULL_NONE,  // No pull-up or pull-down
    GPIO_PULL_UP,   // Pull-up resistor enabled
    GPIO_PULL_DOWN, // Pull-down resistor enabled
}GPIO_Pull_t;

// Function prototype
void GPIO_Init(char port, int pin, GPIO_Mode_t mode, GPIO_Pull_t pull);

#endif // __GPIO_H__


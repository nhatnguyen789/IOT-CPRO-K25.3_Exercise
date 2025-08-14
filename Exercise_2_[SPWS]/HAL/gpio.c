
#include<stdio.h>
#include"gpio.h"

void GPIO_Init(char port, int pin, GPIO_Mode_t mode, GPIO_Pull_t pull)
{
    //1. Simulate clocking for the corresponding GPIO port 
    // In actual: RCC->APB2ENR |= (1 << Port_bit_position);
    //printf("Clocking GPIO port %c\n", port);

#if 0
    // 2. Simulate setting the mode of the GPIO pin
    switch(mode)
    {
        case GPIO_MODE_INPUT:
            printf("INPUT");
            break;
        case GPIO_MODE_OUPUT_PP:
            printf("OUTPUT_PP");
            break;
        case GPIO_MODE_ANALOG:
            printf("ANALOG");
            break;
    }

    switch(pull)
    {
        case GPIO_PULL_NONE:
            printf(" with NO PULL!\n");
            break;
        case GPIO_PULL_UP:
            printf(" with PULL UP!\n");
            break;
        case GPIO_PULL_DOWN:
            printf(" with PULL DOWN!\n");
            break;
    }
#endif
}
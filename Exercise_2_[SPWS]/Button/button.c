// include header files
#include <stdio.h>
#include "button.h"
#include "../App/config.h"
#include "../HAL/gpio.h"
#include "../Logging/logging.h"

// global constants


//global data type


// local variables
static int mock_button_input = 0;
static bool g_toggle_mode_pressed = false;
static bool g_manual_water_pressed = false;

// local function prototype
void Button_Init(void)
{
    // Initialize toggle mode button
    GPIO_Init(BUTTON_TOGGLE_MODE_PORT, BUTTON_TOGGLE_MODE_PIN, GPIO_MODE_INPUT, GPIO_PULL_UP);

    // Initialize manual mode button
    GPIO_Init(BUTTON_MANUAL_WATER_PORT, BUTTON_MANUAL_WATER_PIN, GPIO_MODE_INPUT, GPIO_PULL_UP);

    // Log Initialization
    Logging_Send(LOG_BUTTON_INIT);
}
#if 0
void Button_Scan(void)
{
    // reset the button states
    g_toggle_mode_pressed = false;
    g_manual_water_pressed = false;

    // ask from user to press the button
    printf("\nPress a key ['t/T': Toggle] or ['m/M': Manual] or [Enter = Skip]: ");

    // Simulate button press detection
    char input = getchar();

    // SWITCH CASE to check which button is pressed
    // if 't'/'T' is pressed -> Toggle Mode Button
    // if 'm'/'M' is pressed -> Manual Mode Button
    switch(input)
    {
        case 't':
        case 'T':
            g_toggle_mode_pressed = true;
            Logging_Send(LOG_BUTTON_AUTOMATIC);
            break;
        case 'm':
        case 'M':
            g_manual_water_pressed = true;
            Logging_Send(LOG_BUTTON_MANUAL);
            break;
        case '\n':
            break;
        default:
            while(getchar() != '\n'); // Clear the input buffer
            break;
    }
}
#endif
Button_t Button_CheckState(void)
{
    printf("\nEnter action Button: [1]: Toggle Mode, [2]: Manual Mode, [0]: Skip: ");
    scanf("%d", &mock_button_input);

    switch(mock_button_input)
    {
        case 1:
            return BUTTON_MODE_TOGGLE; // Toggle mode button pressed
        case 2:
            return BUTTON_MANUAL_WATER; // Manual mode button pressed
        default:
            return BUTTON_NONE; // No button pressed

    }
}
bool Button_IsToggleModePresed(void)
{
    return g_toggle_mode_pressed;
}
bool Button_IsManualWaterPresed(void)
{
    return g_manual_water_pressed;
}


// global function definition

#include<stdio.h>
#include<stdlib.h>
#include"led_driver.h"

/**
 * @brief Static variables to store the internal status of the driver.
 * - 'static' Make sure these variable can only be accessed insdie this file.
 * - They exist throughout the life of the program.
 */
// Pointer to memory area (buffer) that stores the color of all pixels.
static uint32_t *g_led_buffer = NULL; 
// The variable stores the number of pixels of the LED strip.
static size_t g_num_pixels = 0;

int led_init(size_t num_pixels)
{
    // If the buffer already exists, free it before creating a new one.
    if(g_led_buffer != NULL)
    {
        free(g_led_buffer);
    }

    // Use calloc to allocate memory for 'num_pixels' elements,
    // each element has a size of sizeof(uint32_t).
    // calloc will also automatically initialize the entire memory area to 0 (black).
    g_led_buffer = (uint32_t*)calloc(num_pixels, sizeof(uint32_t));

    //Check if the allocation was successful.
    if(g_led_buffer == NULL)
    {
        g_num_pixels = 0;
        printf("Allocation memory is failed...\n");
        return -1;
    }
    // Save the number of pixels and return 0 to signal success.
    printf("Allocation memory is succesful!\n");
    g_num_pixels = num_pixels;
    return 0;
}
void led_shutdown()
{
    // Only free memory if the pointer is not NULL.
    if(g_led_buffer != NULL)
    {
        free(g_led_buffer);
        // Reset the pointer to NULL and the pixel count to 0 to avoid errors 
        // like "dangling pointer" or "double free".
        g_led_buffer = NULL;
        g_num_pixels = 0;
    }
}
void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b)
{
    // Boundary checking: If index is outside of valid range, function will exit 
    // to avoid writing to invalid memory.
    if(index >= g_num_pixels)
    {
        return;
    }
    // **Here's the meat of the problem: Bitwise Operations**
    // Required format: 0x00 G R B
    // 1. Shift the 8 bits of Green 16 places to the left.
    // 2. Shift the 8 bits of Red 8 places to the left.
    // 3. Blue is in the correct position.
    // 4. Use the OR operator (|) to combine the 3 shifted values together.
    // Example: g=0xFF, r=0xCC, b=0xAA
    // g << 16  ->  0x00FF0000
    // r << 8   ->  0x0000CC00
    // b        ->  0x000000AA
    // OR lại   ->  0x00FFCCAA
    uint32_t color = ((uint32_t)g << 16) | ((uint32_t)r << 8) | ((uint32_t)b);

    // Assign the packed color value to the correct position in the buffer.
    g_led_buffer[index] = color;
}
void led_fill(uint8_t r, uint8_t g, uint8_t b)
{
    // Compute the 32-bit color value only once.
    uint32_t color = ((uint32_t)g << 16) | ((uint32_t)r << 8) | ((uint32_t)b);

    // Use a loop to assign this color value to all pixels.
    for(int i = 0; i < g_num_pixels; i++)
    {
        g_led_buffer[i] = color;
    }
}
void led_clear()
{
    // Turning off all lights is a special case of painting (0,0,0) black.
    led_fill(0, 0, 0);
}
const uint32_t* led_get_buffer()
{
    return g_led_buffer;
}
size_t led_get_pixel_count()
{
    return g_num_pixels;
}
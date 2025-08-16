//include guards -> Avoid compilation errors when 
//this file is included multiple times
#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

// include header files
#include<stdint.h>  //  uint8_t, uint32_t
#include<stddef.h>  // size_t

//constant

//Data type

//function prototype

/**
 * @brief Initializes a buffer for the LED strip with the given number of pixels.
 *
 * @param num_pixels Number of pixels (LEDs) on the strip.
 * @return 0 if successful, -1 if failed (e.g. memory allocation failed).
 */
int led_init(size_t num_pixels);

/**
 * @brief Frees the memory allocated to the LED strip.
 * This function should be called when the driver is no longer in use to avoid memory leaks.
 */
void led_shutdown();

/**
 * @brief Set the color of a specific pixel at a position (index) on the strip.
 *
 * @param index The position of the pixel to be colored (starting from 0).
 * @param r Red color value: from 0 to 255.
 * @param g Green color value: from 0 to 255.
 * @param b Blue color value: from 0 to 255.
 */
void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief Color the entire LED strip with a single color.
 *
 * @param r Red color value: from 0 to 255.
 * @param g Green color value: from 0 to 255.
 * @param b Blue color value: from 0 to 255.
 */
void led_fill(uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief Turn of all pixels on the strip (by setting their color to back).
 */
void led_clear();

/**
 * @brief Get a const pointer (read only) pointer to the data buffer.
 * Used to check or send data.
 *
 * @return Constant pointer pointing to the first element of the buffer.
 */
const uint32_t* led_get_buffer();

/**
 * @brief Get the number of pixels on the LED strip.
 *
 * @return Number of pixels.
 */
size_t led_get_pixel_count();

//extern variables

#endif// __LED_DRIVER_H__

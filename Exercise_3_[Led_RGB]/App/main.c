#include<stdio.h>
#include<stdlib.h>
#include"../Led/led_driver.h"

#define NUMBER_PIXEL 10

void print_buffer_state()
{
    const uint32_t* buffer = led_get_buffer();
    size_t count = led_get_pixel_count();
    printf("Current Buffer State: (%zu pixels):\n", count);
    for(size_t i = 0; i < count; ++i)
    {
        // 0x%08X: Print Hexa number, always 8 characters, missing characters are replaced by 0.
        printf("Pixel[%zu]: 0x%08X \n", i, buffer[i]);
    }
    printf("-------------------------------------\n");
}

int main()
{
    // 1. Initialize an LED strip with 10 pixels.
    printf("Step 1 & 2: Initializing LED strip with 10 pixels.\n");
    if(led_init(NUMBER_PIXEL) != 0)
    {
        printf("Failed to initialize LED strip!\n");
        return 1;
    }

    // 2. Check buffer is initialized 0 value
    print_buffer_state();
    // const uint32_t *buffer = led_get_buffer();
    // for(int i = 0; i < NUMBER_PIXEL; i++)
    // {
    //     printf("Value pixel %d: %d\n", i, buffer[i]);
    // }

    // 3. set the first pixel become red 
    printf("Step 3: Setting pixel 0 to RED (255, 0, 0).\n");
    led_set_pixel_color(0, 255, 0, 0);

    // 4. Set the final pixel become blue
    printf("Step 4: Setting pixel 9 to BLUE (0, 0, 255).\n");
    led_set_pixel_color(9, 0, 0, 255);

    //5. Set the fourth pixel become white
    printf("Step 5: Setting pixel 4 to WHITE (255, 255, 255).\n");
    led_set_pixel_color(4, 255, 255, 255);

    //6. get pointer to data buffer
    const uint32_t *buffer = led_get_buffer();

    //7. Print hexa value at 0, 4, 9 index
    printf("Step 6 & 7: Verifying specific pixel values.\n");
    printf(" - Pixel[0] value: 0x%08X (EXPECTED: 0x0000FF00)\n", buffer[0]);
    printf(" - Pixel[4] value: 0x%08X (EXPECTED: 0x00FFFFFF)\n", buffer[4]);
    printf(" - Pixel[9] value: 0x%08X (EXPECTED: 0x000000FF)\n", buffer[9]);
    printf("-------------------------------------\n");

    //8. Call the led_fill() function to set all pixels to Green (0, 255, 0).
    printf("Step 8 & 9: Filling the entirte strip with GREEN (0, 255, 0). \n");
    led_fill(0, 255, 0);

    // 9. Check the buffer again to make sure everything is green.
    print_buffer_state(); //All values must be 0x00FF0000
 
    //10. Free memory
    printf("Step 10: Shutting down the driver and freeing memory.\n");
    led_shutdown();

    // Check after shutdown
    if(led_get_buffer() == NULL && led_get_pixel_count() == 0)
    {
        printf("Driver shut down successfully.\n");
    }
    else
    {
        printf("Driver shutdown failed\n");
    }

    return 0;
}


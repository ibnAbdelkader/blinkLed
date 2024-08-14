#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
void app_main(void)
{
    // Initializing PIN22 as Input with Pull up resistor.
    gpio_set_direction(GPIO_NUM_22, GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_22, GPIO_PULLUP_ONLY);
    // Initializing PIN26 as output.
    gpio_set_direction(GPIO_NUM_26, GPIO_MODE_OUTPUT);
    while (true)
    {
        if (gpio_get_level(GPIO_NUM_22))
            gpio_set_level(GPIO_NUM_26, 0);
        else
        {
            gpio_set_level(GPIO_NUM_26, 1);
        }
        vTaskDelay(10);
    }
}

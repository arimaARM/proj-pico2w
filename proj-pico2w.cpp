#include <cmath> 
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include <cstdio>

extern "C"{
#include <ssd1306.h>
}

#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

#define BUTTON_PIN_RIGHT 2
#define BUTTON_PIN_LEFT 6
#define BUTTON_PIN_UP 4
#define BUTTON_PIN_DOWN 5
#define BUTTON_PIN_CENTER 7

#define I2C_PORT i2c0
#define I2C_SDA 16
#define I2C_SCL 17

int main()
{
    stdio_init_all();

    i2c_init(I2C_PORT, 400*1000);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    gpio_init(BUTTON_PIN_RIGHT);
    gpio_set_dir(BUTTON_PIN_RIGHT, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_RIGHT);

    gpio_init(BUTTON_PIN_LEFT);
    gpio_set_dir(BUTTON_PIN_LEFT, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_LEFT);

    gpio_init(BUTTON_PIN_UP);
    gpio_set_dir(BUTTON_PIN_UP, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_UP);

    gpio_init(BUTTON_PIN_DOWN);
    gpio_set_dir(BUTTON_PIN_DOWN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_DOWN);

    gpio_init(BUTTON_PIN_CENTER);
    gpio_set_dir(BUTTON_PIN_CENTER, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_CENTER);
}

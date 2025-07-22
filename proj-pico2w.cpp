#include <iostream>
#include <cmath> 
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 3
#define BUTTON_PIN_3 4


#ifndef LED_DELAY_MS
#define LED_DELAY_MS 500
#endif

/*
#define I2C_PORT i2c0
#define I2C_SDA //select your port 
#define I2C_SCL //select your port 
*/
using namespace std; 

int pico_led_init(void) {
#if defined(PICO_DEFAULT_LED_PIN)
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
#elif defined(CYW43_WL_GPIO_LED_PIN)
    return cyw43_arch_init();
#endif
}

void pico_set_led(bool led_on) {
#if defined(PICO_DEFAULT_LED_PIN)
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
#elif defined(CYW43_WL_GPIO_LED_PIN)
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
#endif
}



int main()
{
    stdio_init_all();

    //i2c_init(I2C_PORT, 400*1000); // I2C Initialisation. Using it at 400Khz.

    gpio_init(BUTTON_PIN_1);
    gpio_set_dir(BUTTON_PIN_1, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_1);

    gpio_init(BUTTON_PIN_2);
    gpio_set_dir(BUTTON_PIN_2, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_2);

    gpio_init(BUTTON_PIN_3);
    gpio_set_dir(BUTTON_PIN_3, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_3);

        int rc = pico_led_init(); 
    if (rc != PICO_OK){
        cout << "Initiliation failed" << endl; 
    }   

     while(true){
        if(!gpio_get(BUTTON_PIN_1)){
            pico_set_led(true);
            sleep_ms(LED_DELAY_MS);
            pico_set_led(false);
        }
        if(!gpio_get(BUTTON_PIN_2)){
            pico_set_led(true);
            sleep_ms(LED_DELAY_MS);
            pico_set_led(false);
        }
        if(!gpio_get(BUTTON_PIN_3)){
            pico_set_led(true);
            sleep_ms(LED_DELAY_MS);
            pico_set_led(false);
        }
    }


    /*
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);       // For more examples of I2C use see https://github.com/raspberrypi/pico-examples/tree/master/i2c
    */

   
}

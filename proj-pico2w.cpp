#include <iostream>
#include <cmath> 
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 3
#define BUTTON_PIN_3 4
/*
#define I2C_PORT i2c0
#define I2C_SDA //select your port 
#define I2C_SCL //select your port 
*/
using namespace std; 

int main()
{
    stdio_init_all();

    //i2c_init(I2C_PORT, 400*1000); // I2C Initialisation. Using it at 400Khz.

    stdio_init_all();
    gpio_init(BUTTON_PIN_1);
    gpio_set_dir(BUTTON_PIN_1, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_1);

    while(true){
        if(!gpio_get(BUTTON_PIN_1)){
            cout << "Pressed button 1" << endl; 
        } 
        sleep_ms(50);
    }
    stdio_init_all();
    gpio_init(BUTTON_PIN_2);
    gpio_set_dir(BUTTON_PIN_2, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_2);

    while(true){
        if(!gpio_get(BUTTON_PIN_2)){
            cout << "Pressed button 2" << endl; 
        } 
        sleep_ms(50);
    }
    stdio_init_all();
    gpio_init(BUTTON_PIN_3);
    gpio_set_dir(BUTTON_PIN_3, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_3);

    while(true){
        if(!gpio_get(BUTTON_PIN_3)){
            cout << "Pressed button 3" << endl; 
        } 
        sleep_ms(50);
    }
    /*
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);       // For more examples of I2C use see https://github.com/raspberrypi/pico-examples/tree/master/i2c
    */

   
}

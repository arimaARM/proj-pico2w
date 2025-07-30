#include "pico/stdlib.h"
extern "C" {
#include <ssd1306.h>
}
#include <cstdio>

// Button pins
#define BUTTON_PIN_RIGHT 2
#define BUTTON_PIN_LEFT 6
#define BUTTON_PIN_UP 4
#define BUTTON_PIN_DOWN 5
#define BUTTON_PIN_CENTER 7

// I2C pins
#define I2C_SDA 16
#define I2C_SCL 17

// OLED settings
#define I2C_PORT i2c0
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

// Initialize a button with internal pull-up
void init_button(uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);
}

// Check and return name of the pressed button
const char* get_pressed_button() {
    if (!gpio_get(BUTTON_PIN_RIGHT)) return "  Right";
    if (!gpio_get(BUTTON_PIN_LEFT)) return "  Left";
    if (!gpio_get(BUTTON_PIN_UP)) return "  Up";
    if (!gpio_get(BUTTON_PIN_DOWN)) return "  Down";
    if (!gpio_get(BUTTON_PIN_CENTER)) return "  Center";
    return "Push Buttons;)";
}

int main() {
    stdio_init_all();
    sleep_ms(2000);  // Wait for serial console

    // Init OLED
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);

    ssd1306_t oled;
    oled.external_vcc = false;

    bool ok = ssd1306_init(&oled, SCREEN_WIDTH, SCREEN_HEIGHT, OLED_ADDR, I2C_PORT);

    if (!ok) {
        printf("OLED init failed!\n");
        return 1;
    }

    // Init buttons
    init_button(BUTTON_PIN_RIGHT);
    init_button(BUTTON_PIN_LEFT);
    init_button(BUTTON_PIN_UP);
    init_button(BUTTON_PIN_DOWN);
    init_button(BUTTON_PIN_CENTER);

    printf("OLED and buttons ready.\n");

    char msg[32];

    while (true) {
        const char* btn = get_pressed_button();

        // Draw pressed button to screen
        snprintf(msg, sizeof(msg), "%s", btn);
        ssd1306_clear(&oled);
        ssd1306_draw_string(&oled, 0, 0, 2, msg);
        ssd1306_show(&oled);

        sleep_ms(150); // debounce delay
    }
}

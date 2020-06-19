#include <SPI.h>
#include <Wire.h>
#include "pusheen.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define DELAY_BOUNCE 333
#define DELAY_SLEEP  1000

void setup() {
    Serial.begin(115200);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.dim(true);
    display.clearDisplay();
}

void loop() {
    pusheen_bounce(10);
    pusheen_sleep(5);
}

void pusheen_bounce(uint8_t t) {
    for (uint8_t i = 0; i < t; i++) {
        display.clearDisplay();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_1, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_BOUNCE);

        display.clearDisplay();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_2, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_BOUNCE);
    }
}

void pusheen_sleep(uint8_t t) {
    for (uint8_t i = 0; i < t; i++) {
        display.clearDisplay();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_1_sleep, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_SLEEP);

        display.clearDisplay();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_2_sleep, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_SLEEP);
    }
}

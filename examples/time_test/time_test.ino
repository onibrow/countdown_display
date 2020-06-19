#include <SPI.h>
#include <Wire.h>
#include "time_test.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     4
#define DELAY_BOUNCE 333
#define DELAY_SLEEP  1000

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RTC_DS3231 rtc;

void setup() {
    Serial.begin(115200);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.dim(true);
    display.clearDisplay();

    if (! rtc.begin()) {
        Serial.println("Couldn't find RTC");
        Serial.flush();
        abort();
    }
}

void loop() {
    pusheen_bounce(4);
    pusheen_sleep(2);
    print_time();
}

void print_time() {
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
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

#include <SPI.h>
#include <Wire.h>
#include "mac_time.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ds3231.h>
#include <LowPower.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     4

#define SCREEN_TIME  5000
#define DELAY_BOUNCE  250
#define DELAY_SLEEP  1000

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
volatile struct ts t;
const uint8_t wake_pin = 3;
const byte ledPin = 13;
volatile byte state = LOW;

void wakeUp()
{
    // Just a handler for the pin interrupt.
    state = !state;
}

void setup() {
    Serial.begin(115200);
    pinMode(wake_pin, INPUT);
    pinMode(ledPin, OUTPUT);

    // OLED Display Setup {{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.dim(true);
    display.clearDisplay();
    display.display();
    // }}

    /*
    // DS3231 Setup {{
    Wire.begin();
    DS3231_init(DS3231_INTCN);

    t.hour =   12;
    t.min  =   30;
    t.sec  =    0;
    t.mday =   25;
    t.mon  =   12;
    t.year = 2019;

    DS3231_set(t);
    // }}
     */

    Serial.println("Attached Interrupt!");
    delay(5);
}

void loop() {
    digitalWrite(ledPin, state);
    attachInterrupt(digitalPinToInterrupt(wake_pin), wakeUp, RISING);

    // Enter power down state with ADC and BOD module disabled.
    // Wake up when wake up pin is low.
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

    // Disable external pin interrupt on wake up pin.
    detachInterrupt(digitalPinToInterrupt(wake_pin));
    get_datetime();
}

void get_datetime() {
    // DS3231_get(&t);
    // Random Gen {{
    t.hour = random(0, 24);
    t.min  = random(0, 60);
    t.sec  = random(0, 60);
    t.mday = random(0, 31);
    t.mon  = random(0, 12);
    t.year = 2020;
    // }

    if (t.hour < 8) {
        pusheen_sleep();
    }
    else {
        pusheen_bounce();
    }
}

void draw_datetime() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);

    if (t.mon < 10) {
        display.print("0");
    }
    display.print(t.mon);
    display.print(" Month");
    if (t.mon != 1) {
        display.print("s");
    }
    display.print("\n");

    if (t.mday < 10) {
        display.print("0");
    }
    display.print(t.mday);
    display.print(" Day");
    if (t.mday != 1) {
        display.print("s");
    }
    display.print("\n");

    if (t.hour < 10) {
        display.print("0");
    }
    display.print(t.hour);
    display.print(" Hour");
    if (t.hour != 1) {
        display.print("s");
    }
    display.print("\n");

    if (t.min < 10) {
        display.print("0");
    }
    display.print(t.min);
    display.print(" Minute");
    if (t.min != 1) {
        display.print("s");
    }
    display.print("\n");
}


void pusheen_bounce() {
    for (uint8_t i = 0; i < round(SCREEN_TIME / DELAY_BOUNCE / 2 + 0.5); i++) {
        draw_datetime();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_1, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_BOUNCE);

        draw_datetime();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_2, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_BOUNCE);
    }
    display.clearDisplay();
    display.display();
}

void pusheen_sleep() {
    for (uint8_t i = 0; i < round(SCREEN_TIME / DELAY_SLEEP / 2 + 0.5); i++) {
        draw_datetime();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_1_sleep, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_SLEEP);

        draw_datetime();
        display.drawBitmap(
                (display.width()  - PUSHEEN_WIDTH_BIG),
                (display.height() - PUSHEEN_HEIGHT_BIG),
                pusheen_2_sleep, PUSHEEN_WIDTH_BIG, PUSHEEN_HEIGHT_BIG, 1);
        display.display();
        delay(DELAY_SLEEP);
    }
    display.clearDisplay();
    display.display();
}

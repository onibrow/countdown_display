#include <SPI.h>
#include <Wire.h>
#include "mac_time.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"
#include <LowPower.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     4

#define SCREEN_TIME  5000
#define DELAY_BOUNCE  250
#define DELAY_SLEEP  1000

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RTC_DS3231 rtc;
DateTime now;
TimeSpan diff;
DateTime end_date = DateTime(2020, 9, 1, 20, 0, 0);
DateTime compile_time = DateTime(2020, 6, 13, 12, 30, 3);

const uint8_t wake_pin = 3;
const uint8_t ds_pin = 16;

void wakeUp() {
  return;
}

void setup() {
  pinMode(wake_pin, INPUT);
  pinMode(ds_pin, OUTPUT);
  digitalWrite(ds_pin, LOW);

  // OLED Display Setup {{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;);
  }
  display.dim(true);
  display.clearDisplay();
  display.display();
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  // }}

  // DS3231 Setup {{
  if (! rtc.begin()) {
    for (;;);
  }
  if (rtc.lostPower()) {
    rtc.adjust(compile_time);
  // }}

    delay(5);
  }
}

void loop() {
  attachInterrupt(digitalPinToInterrupt(wake_pin), wakeUp, RISING);

  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  detachInterrupt(digitalPinToInterrupt(wake_pin));
  get_datetime();
}

void get_datetime() {
  display.ssd1306_command(SSD1306_DISPLAYON);

  // Load in current time
  digitalWrite(ds_pin, HIGH);
  delay(5);
  now = rtc.now();
  digitalWrite(ds_pin, LOW);
  if (now < end_date) {
    diff = end_date - now;
  }
  else {
    diff = TimeSpan(0);
  }

  if (now.hour() < 8) {
    pusheen_sleep();
  }
  else {
    pusheen_bounce();
  }
  display.ssd1306_command(SSD1306_DISPLAYOFF);
}

void draw_datetime() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 4);

  // Month
  /*
    if (now.month() < 10) {
      display.print("0");
    }
    display.print(now.month());
    display.print(" Month");
    if (now.month() != 1) {
      display.print("s");
    }
    display.print("\n");
  */

  if (diff.days() < 10) {
    display.print("0");
  }
  display.print(diff.days());
  display.print(" Day");
  if (diff.days() != 1) {
    display.print("s");
  }
  display.print("\n");

  if (diff.hours() < 10) {
    display.print("0");
  }
  display.print(diff.hours());
  display.print(" Hour");
  if (diff.hours() != 1) {
    display.print("s");
  }
  display.print("\n");

  if (diff.minutes() < 10) {
    display.print("0");
  }
  display.print(diff.minutes());
  display.print(" Minute");
  if (diff.minutes() != 1) {
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

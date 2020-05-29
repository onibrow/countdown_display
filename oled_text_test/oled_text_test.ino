#include <SPI.h>
#include <Wire.h>
#include "oled_text_test.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char buff[32];
char month_[3];
char day_[3];
char hour_[3];
char minute_[3];

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  memset(buff, 0, 32);
  test_text();
  display.clearDisplay();
}

void loop() {

}

void serialEvent() {
  if (Serial.available()) {
    size_t len = Serial.readBytesUntil('\n', buff, 32);
    if (len != 12) {
      Serial.println("Invalid Format");
    }
    else {
      get_mdhm();
      print_mdhm();
    }
    //    test_text();
    memset(buff, 0, 32);
  }
}

void get_mdhm() {
  memcpy(month_, buff, 2); month_[2] = '\0';
  memcpy(day_, buff + 3, 2); day_[2] = '\0';
  memcpy(hour_, buff + 6, 2); hour_[2] = '\0';
  memcpy(minute_, buff + 9, 2); minute_[2] = '\0';
}

void print_mdhm() {
  display.clearDisplay();
  display.stopscroll();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  display.print(month_);
  display.print(" Months\n");
  display.print(day_);
  display.print(" Days\n");
  display.print(hour_);
  display.print(" Hours\n");
  display.print(minute_);
  display.print(" Minutes\n");

  display.display();
}

void test_text() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 11);

  // Get Date
  display.println(buff);
  // End Get Date

  display.display();
  display.startscrollright(0x00, 0x0F);
}

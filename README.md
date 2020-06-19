# Countdown Display

A low power countdown display

## Features

### 128x32 OLED Display

[SSD1306](https://smile.amazon.com/gp/product/B07X35H728/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1) 128x32 OLED display compatible with Adafruit's [OLED library](https://github.com/adafruit/Adafruit_SSD1306), featuring a shut down mode for low power consumption, capable of running off 3.6V to 5V.

### Low Power

ATMega328P was chosen for the microcontroller of choice, for its low power sleep feature and small footprint. Running off of a LiPo battery, it can enter a deep sleep that consumes less that 10uA of current utilizing the external interrupt (generated using a push button) based indefinite sleep, from the [Arduino LowPower library](https://www.arduino.cc/en/Reference/ArduinoLowPower). The fuses are burned to use an 8MHz external clock and to brown out at 3V.

### RTC

A real time clock was used to keep track of the current date and time, running off of an ultra low power DS3231 and a back up coin cell. With the coin cell, the time keeping feature can run for 5 years, while the ultra low power could be directly sourced from one of the digital output pins on the ATMega to make power on and off of the RTC much easier. The Adafrtui [RTClib](https://github.com/adafruit/RTClib) was used for this chip.

### LiPo

A 40mAh LiPo battery was chosen as the main power supply for this device. Considering an ON current of about 12mA and a deep sleep current of 10uA, a quick calculation assuming that the device will be powered on for 2 minutes in any given day leaves the device an astounding 2 month life on a single charge. It is also equiped with an [MCP73831](https://www.microchip.com/wwwproducts/en/en024903) single cell, LiPo charge management controller to recharge the battery safely over a microUSB connection.

## Gallery

![photo](img/countdown_hardware.jpg)

![gif](img/countdown.gif)

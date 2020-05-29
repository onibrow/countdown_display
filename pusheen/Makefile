### DISCLAIMER
### This is an example Makefile and it MUST be configured to suit your needs.
### For detailed explanations about all of the available options, please refer
### to https://github.com/sudar/Arduino-Makefile/blob/master/arduino-mk-vars.md
### Original project where this Makefile comes from: https://github.com/WeAreLeka/Bare-Arduino-Project

### ARDMK_DIR
### Path to the Arduino-Makefile directory.
ARDMK_DIR=/usr/share/arduino

### ARDUINO_DIR
### Path to the Arduino application and resources directory.
### Linux: 
ARDUINO_DIR=/usr/lib/arduino-1.8.10

### USER_LIB_PATH
### Path to where the your project's libraries are stored.
USER_LIB_PATH:=$(HOME)/Arduino/libraries/*

ARDUINO_LIB_PATH:=$(HOME)/Arduino/libraries
ARDUINO_LIBS = SPI Wire Adafruit_GFX Adafruit_SSD1306 Adafruit_BusIO

### BOARD_TAG
### It must be set to the board you are currently using. (i.e uno, mega2560, etc.)
BOARD_TAG         = uno

### MONITOR_BAUDRATE
### It must be set to Serial baudrate value you are using.
MONITOR_BAUDRATE  = 115200

### AVR_TOOLS_DIR
### Path to the AVR tools directory such as avr-gcc, avr-g++, etc.
### Linux: (remove the one you don't want)
#AVR_TOOLS_DIR=/usr/include:$(HOME)/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5
AVR_TOOLS_DIR= $(HOME)/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5

### AVRDUDE
### Path to avrdude directory.
AVRDUDE          = $(HOME)/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/bin/avrdude
AVRDUDE_CONF = $(HOME)/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf


### CFLAGS_STD
### Set the C standard to be used during compilation. Documentation (https://github.com/WeAreLeka/Arduino-Makefile/blob/std-flags/arduino-mk-vars.md#cflags_std)
CFLAGS_STD        = -std=gnu11

### CXXFLAGS_STD
### Set the C++ standard to be used during compilation. Documentation (https://github.com/WeAreLeka/Arduino-Makefile/blob/std-flags/arduino-mk-vars.md#cxxflags_std)
CXXFLAGS_STD      = -std=gnu++11

### CXXFLAGS
### Flags you might want to set for debugging purpose. Comment to stop.
CXXFLAGS         += -pedantic -Wall -Wextra

### MONITOR_PORT
### The port your board is connected to. Using an '*' tries all the ports and finds the right one.
MONITOR_PORT      = /dev/ttyACM*
ISP_PROG = usbtiny

### CURRENT_DIR
### Do not touch - used for binaries path
CURRENT_DIR       = $(shell basename $(CURDIR))

### Do not touch - the path to Arduino.mk, inside the ARDMK_DIR
include $(ARDMK_DIR)/Arduino.mk

MONITOR_PORT = /dev/ttyACM* /dev/ttyUSB*
AVRDUDE_OPTS = -v
# ISP_PROG     = usbtiny
ISP_PROG     = stk500v1
AVRDUDE_ARD_PROGRAMMER = stk500v1
ISP_PORT = /dev/ttyACM*
ARDMK_DIR    = /usr/share/arduino

### ARDUINO_DIR
### Path to the Arduino application and resources directory.
### Linux: 
ARDUINO_DIR=/usr/lib/arduino-1.8.10

### USER_LIB_PATH
### Path to where the your project's libraries are stored.
USER_LIB_PATH:=$(HOME)/Arduino/libraries/*

ARDUINO_LIB_PATH:=$(HOME)/Arduino/libraries
ARDUINO_LIBS = SPI Wire Adafruit_GFX Adafruit_SSD1306 Adafruit_BusIO ds3231 LowPower

### BOARD_TAG
### It must be set to the board you are currently using. (i.e uno, mega2560, etc.)
BOARD_TAG         = pro
BOARD_SUB         = 8MHzatmega328
AVRDUDE_ARD_BAUDRATE = 19200
#BOARD_CLOCK       = 8mhz

### MONITOR_BAUDRATE
### It must be set to Serial baudrate value you are using.
MONITOR_BAUDRATE  = 115200

### AVR_TOOLS_DIR
### Path to the AVR tools directory such as avr-gcc, avr-g++, etc.
AVR_TOOLS_DIR= $(HOME)/.arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5

### AVRDUDE
### Path to avrdude directory.
AVRDUDE          = $(HOME)/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/bin/avrdude
AVRDUDE_CONF = $(HOME)/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf

### C Flags
CFLAGS_STD        = -std=gnu11
CXXFLAGS_STD      = -std=gnu++11
CXXFLAGS         += -pedantic -Wall -Wextra

CURRENT_DIR       = $(shell basename $(CURDIR))
include $(ARDMK_DIR)/Arduino.mk

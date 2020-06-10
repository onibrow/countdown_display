// **** INCLUDES *****
#include "LowPower.h"

// Use pin 2 as wake up pin
const int wakeUpPin = 2;
const byte ledPin = 13;
volatile byte state = LOW;

void wakeUp()
{
    // Just a handler for the pin interrupt.
    state = !state;
}

void setup()
{
    pinMode(ledPin, OUTPUT);
    // Configure wake up pin as input.
    // This will consumes few uA of current.
    pinMode(wakeUpPin, INPUT_PULLUP);
}

void loop()
{
    // Allow wake up pin to trigger interrupt on low.
    digitalWrite(ledPin, state);
    attachInterrupt(digitalPinToInterrupt(wakeUpPin), wakeUp, FALLING);

    // Enter power down state with ADC and BOD module disabled.
    // Wake up when wake up pin is low.
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

    // Disable external pin interrupt on wake up pin.
    detachInterrupt(digitalPinToInterrupt(wakeUpPin));

    // Do something here
    // Example: Read sensor, data logging, data transmission.
}

// **** INCLUDES *****
#include "LowPower.h"

// Use pin 2 as wake up pin
const int wakeUpPin = 1;
const byte ledPin = 2;
volatile byte state = LOW;

void wakeUp()
{
    state = !state;
}

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(wakeUpPin, INPUT_PULLUP);
}

void loop()
{
    digitalWrite(ledPin, state);
//    attachInterrupt(digitalPinToInterrupt(wakeUpPin), wakeUp, FALLING);

    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

    // Disable external pin interrupt on wake up pin.
    detachInterrupt(digitalPinToInterrupt(wakeUpPin));

}

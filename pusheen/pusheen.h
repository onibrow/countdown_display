// pusheen.h

#ifndef _PUSHEEN_H
#define _PUSHEEN_H

#define PUSHEEN_HEIGHT_BIG 32
#define PUSHEEN_WIDTH_BIG 56

void pusheen_bounce(uint8_t t);
void pusheen_sleep(uint8_t t);

static const unsigned char PROGMEM pusheen_1[] = {
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B00000000, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B00000000, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B00000000, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B00000000, B00000011, B00000011, B11110000, B00111111, B11100000, B00000000,
B00000000, B00000011, B00000011, B11110000, B00111111, B11111000, B00000000,
B00000000, B00000011, B00000000, B00000000, B00000000, B00011111, B00000000,
B00000000, B00000111, B00000000, B00000000, B00000000, B00000111, B10000000,
B00000000, B00001110, B00000000, B00000000, B00000000, B00000001, B11000000,
B00000000, B00001100, B01110000, B00000011, B10000000, B00000000, B11100000,
B00000000, B00001100, B01110000, B11000011, B10000000, B00000000, B01110000,
B00000000, B11111100, B01110000, B11000011, B10111100, B00000000, B00110000,
B00000000, B00001100, B00000011, B11110000, B00000000, B00000000, B00011000,
B00000000, B00001100, B00000011, B00110000, B00000000, B00000000, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B11111100, B00000000, B00000000, B00111100, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000011, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000000, B00000110, B00011000,
B00000000, B00001100, B00000000, B00000000, B00000000, B00011100, B00110000,
B00000000, B00001110, B00000000, B00000000, B00000001, B11111000, B01110000,
B00000000, B00000111, B00000000, B00000000, B00000011, B00000000, B11100000,
B00000000, B00000011, B10000000, B00000000, B00000011, B00000001, B11000000,
B00000000, B00000001, B11111111, B11111111, B11111111, B11111111, B10000000,
B00000000, B00000000, B01111111, B11111111, B11111111, B11111110, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

static const unsigned char PROGMEM pusheen_2[] = {
B00000000, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B00000000, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B00000000, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B00000000, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B00000000, B00000011, B00000011, B11110000, B00111111, B11100000, B00000000,
B00000000, B00000011, B00000011, B11110000, B00111111, B11111000, B00000000,
B00000000, B00000011, B00000000, B00000000, B00000000, B00011111, B00000000,
B00000000, B00000111, B00000000, B00000000, B00000000, B00000111, B10000000,
B00000000, B00001110, B00000000, B00000000, B00000000, B00000001, B11000000,
B00000000, B00001100, B01110000, B00000011, B10000000, B00000000, B11100000,
B00000000, B00001100, B01110000, B11000011, B10000000, B00000000, B01110000,
B00000000, B11111100, B01110000, B11000011, B10111100, B00000000, B00110000,
B00000000, B00001100, B00000011, B11110000, B00000000, B00000000, B00110000,
B00000000, B00001100, B00000011, B00110000, B00000000, B00000000, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B11111100, B00000000, B00000000, B00111100, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000011, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000001, B10000110, B00011000,
B00000000, B00001100, B00000000, B00000000, B00000011, B11011100, B00110000,
B00000000, B00001110, B00000000, B00000000, B00000011, B00111000, B01110000,
B00000000, B00000111, B00000000, B00000000, B00000011, B00000000, B11100000,
B00000000, B00000011, B10000000, B00000000, B00000001, B10000001, B11000000,
B00000000, B00000001, B11111111, B11111111, B11111111, B11111111, B10000000,
B00000000, B00000000, B01111111, B11111111, B11111111, B11111110, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

static const unsigned char PROGMEM pusheen_1_sleep[] = {
B11111100, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00001000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00010000, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B00100000, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B01000000, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B11111100, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B00000000, B00000011, B00000011, B11110000, B00111111, B11100000, B00000000,
B00001111, B00000011, B00000011, B11110000, B00111111, B11111000, B00000000,
B00000010, B00000011, B00000000, B00000000, B00000000, B00011111, B00000000,
B00000100, B00000111, B00000000, B00000000, B00000000, B00000111, B10000000,
B00001111, B00001110, B00000000, B00000000, B00000000, B00000001, B11000000,
B00000000, B00001100, B00000000, B00000000, B00000000, B00000000, B11100000,
B00000000, B00001100, B00000000, B11000000, B00000000, B00000000, B01110000,
B00000000, B11111100, B01110000, B11000011, B10111100, B00000000, B00110000,
B00000000, B00001100, B00000011, B11110000, B00000000, B00000000, B00011000,
B00000000, B00001100, B00000011, B00110000, B00000000, B00000000, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B11111100, B00000000, B00000000, B00111100, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000011, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000000, B00000110, B00011000,
B00000000, B00001100, B00000000, B00000000, B00000000, B00011100, B00110000,
B00000000, B00001110, B00000000, B00000000, B00000001, B11111000, B01110000,
B00000000, B00000111, B00000000, B00000000, B00000011, B00000000, B11100000,
B00000000, B00000011, B10000000, B00000000, B00000011, B00000001, B11000000,
B00000000, B00000001, B11111111, B11111111, B11111111, B11111111, B10000000,
B00000000, B00000000, B01111111, B11111111, B11111111, B11111110, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

static const unsigned char PROGMEM pusheen_2_sleep[] = {
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B01111110, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B00000100, B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
B00001000, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B00010000, B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
B00100000, B00000011, B00000011, B11110000, B00111111, B11100000, B00000000,
B01111110, B00000011, B00000011, B11110000, B00111111, B11111000, B00000000,
B00000000, B00000011, B00000000, B00000000, B00000000, B00011111, B00000000,
B00001111, B00000111, B00000000, B00000000, B00000000, B00000111, B10000000,
B00000010, B00001110, B00000000, B00000000, B00000000, B00000001, B11000000,
B00000100, B00001100, B00000000, B00000000, B00000000, B00000000, B11100000,
B00001111, B00001100, B00000000, B11000000, B00000000, B00000000, B01110000,
B00000000, B11111100, B01110000, B11000011, B10111100, B00000000, B00110000,
B00000000, B00001100, B00000011, B11110000, B00000000, B00000000, B00011000,
B00000000, B00001100, B00000011, B00110000, B00000000, B00000000, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B11111100, B00000000, B00000000, B00111100, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000000, B00011000,
B00000000, B00011000, B00000000, B00000000, B00000000, B00000011, B00011000,
B00000000, B00011100, B00000000, B00000000, B00000000, B00000110, B00011000,
B00000000, B00001100, B00000000, B00000000, B00000000, B00011100, B00110000,
B00000000, B00001110, B00000000, B00000000, B00000001, B11111000, B01110000,
B00000000, B00000111, B00000000, B00000000, B00000011, B00000000, B11100000,
B00000000, B00000011, B10000000, B00000000, B00000011, B00000001, B11000000,
B00000000, B00000001, B11111111, B11111111, B11111111, B11111111, B10000000,
B00000000, B00000000, B01111111, B11111111, B11111111, B11111110, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

#endif // _PUSHEEN_H

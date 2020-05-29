// pusheen.h

#ifndef _PUSHEEN_H
#define _PUSHEEN_H

#define PUSHEEN_HEIGHT_BIG   32
#define PUSHEEN_WIDTH_BIG    48

static const unsigned char PROGMEM pusheen_1[] =
{ B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B11111100, B00110000, B11000011, B00000000, B00000000, B00110000,
  B11111100, B00110000, B11000011, B00000000, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

static const unsigned char PROGMEM pusheen_2[] =
{ B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B11111100, B00110000, B11000011, B00000000, B00000000, B00110000,
  B11111100, B00110000, B11000011, B00000000, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

static const unsigned char PROGMEM pusheen_1_sleep[] =
{ B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B11111100, B00000000, B11000000, B00000000, B00000000, B00110000,
  B11111100, B00110000, B11000011, B00000000, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

static const unsigned char PROGMEM pusheen_2_sleep[] =
{ B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B00110000, B00000011, B00000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000000, B11001100, B00001100, B11000000, B00000000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000011, B11110000, B00111111, B11110000, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00000011, B00000000, B00000000, B00000000, B00001111, B00000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B00001100, B00000000, B00000000, B00111100, B00000000, B11000000,
  B11111100, B00000000, B11000000, B00000000, B00000000, B00110000,
  B11111100, B00110000, B11000011, B00000000, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B00001100, B00000011, B11110000, B00111100, B00000000, B00110000,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B11110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000000, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00110000, B00000000, B00000000, B00000000, B00000011, B00001100,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00001100, B00000000, B00000000, B00000000, B11111100, B00110000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000011, B00000000, B00000000, B00000011, B00000000, B11000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B11111111, B11111111, B11111111, B11111111, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

#endif // _PUSHEEN_H
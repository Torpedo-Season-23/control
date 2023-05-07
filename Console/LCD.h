#ifndef LCD_H
#define LCD_H

#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include "config.h"

class LCD{
private:
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
public:
  void init();
  void update(int16_t *sensors, int* acc, int speed , int8_t dir);
};

#endif

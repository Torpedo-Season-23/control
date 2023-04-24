#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal_I2C.h>


class Lcd {
private:
  LiquidCrystal_I2C lcd;
  int speed;
  bool connected;
  bool acc[8] = { 0 };
public:
  Lcd():lcd(0x27,16,2){};
  void init();
  void update(int speed, bool comm, int *acc);
};

#endif

#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "hiduniversal.h"
#include "PS3USB.h"
#ifdef dobogusinclude
#include "spi4teensy3.h"
#endif
#include <SPI.h>
#include "config.h"


class IController {
protected:
  int acc_array[8];
  int Td_array[3] = { 0 };
  int vertical_frame[2] = { 1500, 1500 };
  bool flags[8] = { 0 };
  uint8_t speeds[3] = { LOW_SPEED_VALUE, NORMAL_SPEED_VALUE, HIGH_SPEED_VALUE };
  int speed = 1;
  USB Usb;
  virtual void update_vmotion() = 0;
  virtual void update_hmotion() = 0;
public:
  IController(){};
  virtual void init();
  virtual void Update() = 0;
  int* get_hframe();
  // void set_hframe(int *array);
  // void set_vframe(int *array);
  int* get_vframe();
  int* get_accframe();
  int getspeed();
};
#endif

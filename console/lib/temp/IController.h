#ifndef _ICONTROLLER_H_
#define _ICONTROLLER_H_

#include <Arduino.h>
#include <PS3USB.h>
#include <hiduniversal.h>

#define LOW_SPEED 42
#define NORMAL_SPEED 85
#define HIGH_SPEED 128

class IController {
 protected:
  int accArray[6];
  int tdArray[3];
  int verticalFrame[2];
  bool flags[8];
  uint8_t speeds[3];
  int speed;
  USB usb;
  virtual void updateVerticalMotion() = 0;
  virtual void updateHorizontalMotion() = 0;

 public:
  IController();
  virtual void init();
  virtual void update() = 0;
  int* getHorizontalFrame();
  int* getVerticalFrame();
  int* getAccFrame();
  int getSpeed();
};

#ifndef _ICONTROLLER_CPP_
#include "IController.cpp"
#endif

#endif
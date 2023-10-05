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
  uint8_t mspeeds[3] = { LOW_SPEED_VALUE_mom, NORMAL_SPEED_VALUE, HIGH_SPEED_VALUE };
  int speed = 1;
  USB Usb;
  virtual void update_vmotion() = 0;
  virtual void update_hmotion() = 0;


public:
  IController(){};
  virtual void init();
  virtual void Update() = 0;
  virtual int8_t getDirection() = 0;
  int* get_hframe();
  int* get_vframe();
  int* get_accframe();
  void set_hframe(int* arr);
  void set_vframe(int* arr);
  uint8_t isAutonomous;
  long timeOfAutonomous;
  int getspeed();
  virtual bool force_stop() = 0;
  virtual bool nrf() = 0;
  virtual void pitching() = 0;
  virtual bool timer() = 0;
  bool isPID();
  // virtual bool isMomented() = 0;
};
#endif

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <PS3USB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>



class Controller {
private:
  uint8_t acc_array[4];
  int Td_array[3]={0};
  int vertical_frame[2]={1500,1500};
  bool flags[4]={0};
  uint8_t speed=1;//The default is the normal speed.

public:
  void init();
  void Update();
  int* get_hframe();
  int* get_vframe();
  uint8_t* get_accframe();
  int getspeed();
private:
  void manageHorizontalMotion();
  void manageVerticalMotion();
};
#endif

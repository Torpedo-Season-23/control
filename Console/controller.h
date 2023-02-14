#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"IController.h"
class PSGamepad:public IController {
private:
  uint8_t acc_array[4];
  int Td_array[3]={0};
  int vertical_frame[2]={1500,1500};
  bool flags[4]={0};
  int speed;

public:
  PSGamepad() : PS3(&Usb) {}
  void Update();
  int* get_hframe();
  int* get_vframe();
  uint8_t* get_accframe();
  int getspeed();
};
#endif

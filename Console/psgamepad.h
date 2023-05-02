#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"IController.h"
class PSGamepad:public IController {
private:
  PS3USB PS3;
  void update_vmotion();
  void update_hmotion();
  void force_stop();
  
public:
  PSGamepad() : PS3(&Usb) {}
  int8_t getDirection();
  void Update();
};
#endif

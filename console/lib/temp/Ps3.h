#ifndef _PS3_H_
#define _PS3_H_

#include "IController.h"

class PS3GamePad : public IController {
 private:
  PS3USB *ps3;
  void updateVerticalMotion();
  void updateHorizontalMotion();

 public:
  PS3GamePad();
  void update();
};

#ifndef _PS3_CPP_
#include "Ps3.cpp"
#endif

#endif
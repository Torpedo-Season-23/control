#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "Ps3.h"

class System {
 private:
  IController* controller;

 public:
  System();
  System(IController* controller);
  void init();
  void update();
};

#ifndef _SYSTEM_CPP_
#include "System.cpp"
#endif

#endif
#ifndef _MNANO_H_
#define _MNANO_H_

#include "config.h"
#include "mapper.h"
#include "motion6.h"
#include "uart.h"

class MNANO {
 private:
  Motion6 *motion;
  UART *uart;
  MotorsMapper *mapper;

 public:
  MNANO();
  void init();
  void update();
};

#ifndef _MNANO_CPP_
#include "mnano.cpp"
#endif

#endif
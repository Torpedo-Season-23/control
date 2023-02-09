#ifndef _E_NANO_
#define _E_NANO_

#include "config.h"
#include "ethernet.h"
#include "euart.h"
#include "mapper.h"

class ENANO {
 private:
  EUART *uart;
  BoxEthernet *ethernet;
  Mapper *mapper;

 public:
  ENANO();
  void init();
  void update();
};

#ifndef _E_NANO_CPP_
#include "enano.cpp"
#endif

#endif
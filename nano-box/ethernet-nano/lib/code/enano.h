#ifndef _E_NANO_
#define _E_NANO_

#include "config.h"
#include "ethernet.h"
#include "euart.h"
#include "mapper.h"

class ENano {
 private:
  EUART *uart;
  BoxEthernet *ethernet;
  Mapper *mapper;

 public:
  ENano();
  void init();
  void update();
  void getSensors();
};

#ifndef _E_NANO_CPP_
#include "enano.cpp"
#endif

#endif
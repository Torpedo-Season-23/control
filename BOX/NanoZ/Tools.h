#ifndef TOOLS_H
#define TOOLS_H
#include "Config.h"

class Tools {

  const int toolPins[TOOLS_COUNT] = { 0 };

public:
  uint8_t *toolsFrame;
  void init();
  void applySignal();
};

#endif
#ifndef TOOLS_H
#define TOOLS_H
#include "Config.h"

class Tools {

  const int toolPins[TOOLS_COUNT] = { A0, A1, A2, A3, A4, A5, 4, 2 };

public:
  uint8_t toolsFrame[TOOLS_COUNT];
  void init();
  void applySignal();
};

#endif

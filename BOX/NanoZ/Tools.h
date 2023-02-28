#ifndef TOOLS_H
#define TOOLS_H
#include "Config.h"

class Tools{
  // first 5 are Grippers pins, last 3 lights pins 
  const int toolPins[TOOLS_COUNT] = {0};
  
  public:
  uint8_t *tool_frame;
  void init();
  void apply_signal();
};

#endif
#ifndef TOOLS_H
#define TOOLS_H
#include "Config.h"

class Tools {
  uint8_t toolPins[SHIFTREGISTER] = { 33, 32, 17 };
  bool toolsFrame[TOOLS_COUNT] = { false };
  void registerWrite(bool *arr);
public:
  Tools(){};
  Tools(int latchPin, int clockPin, int dataPin);
  void init();
  void update();
  bool *getToolsFrame();
  void setToolsFrame(bool *arr);
};

#endif

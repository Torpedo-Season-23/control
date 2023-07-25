#ifndef TOOLS_H
#define TOOLS_H
#include "Config.h"

class Tools {
  const uint8_t toolPins[MUX_CHANALES] = { MUX_CH1_PIN, MUX_CH2_PIN, MUX_CH3_PIN };  //previous pins:  A0, A1, A2, A3, A4, A5, 4, 2
  void setMUX(int number, bool sig);
public:
  bool toolsFrame[TOOLS_COUNT];
  void init();
  void applySignal();
};

#endif

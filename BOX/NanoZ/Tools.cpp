#include "Tools.h"


void Tools::init() {
  for (int i = 0; i < TOOLS_COUNT; i++) {
    pinMode(toolPins[i], OUTPUT); //set tool pins to be Output pins
  }
}

//set signals to tools
void Tools::apply_signal() {
  for (int i = 0; i < TOOLS_COUNT; i++) {
    analogWrite(toolPins[i], this->tool_frame[i]);
  }
}


#include "Tools.h"


void Tools::init() {
  for (int i = 0; i < TOOLS_COUNT; i++) {
    pinMode(toolPins[i], OUTPUT);  //set tool pins to be Output pins
  }
}

//set signals to tools
void Tools::applySignal() {
  for (int i = 0; i < TOOLS_COUNT; i++) {
    digitalWrite(toolPins[i], this->toolsFrame[i]);

  }
}

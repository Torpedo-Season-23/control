#include "Tools.h"


void Tools::init() {
  for (int i = 0; i < TOOLS_COUNT; i++) {
    pinMode(toolPins[i], OUTPUT);  //set tool pins to be Output pins
  }
  pinMode(MUX_SIG_PIN, OUTPUT);
}

//set signals to tools
void Tools::applySignal() {
  for (int i = 0; i < TOOLS_COUNT; i++) {
    setMUX(i,toolsFrame[i]);
  }
}

void Tools::setMUX(int number, bool sig) {
  for (int i = 0; i < MUX_CHANALES; i++) digitalWrite(toolPins[i], bitRead(number, i));
  digitalWrite(MUX_SIG_PIN, sig);
}

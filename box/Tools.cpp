#include "Tools.h"

Tools::Tools(int latchPin , int clockPin , int dataPin) {
  this->toolPins[LatchPin] = latchPin;
  this->toolPins[ClockPin] = clockPin;
  this->toolPins[DataPin] = dataPin;
}
void Tools::init() {
  for (int i = 0; i < SHIFTREGISTER; i++) {
    pinMode(toolPins[i], OUTPUT);  //set tool pins to be Output pins
  }
}
void Tools::update() {
  this->registerWrite(this->toolsFrame);
}

void Tools::registerWrite(bool* arr) {
  byte bitsToSend = 0;
  digitalWrite(this->toolPins[LatchPin], LOW);
  for (int i = 0; i < TOOLS_COUNT; i++) bitWrite(bitsToSend, i, arr[i]);
  shiftOut(this->toolPins[DataPin], this->toolPins[ClockPin], MSBFIRST, bitsToSend);
  digitalWrite(this->toolPins[LatchPin], HIGH);
}

bool * Tools::getToolsFrame() {
  return this->toolsFrame;
}

void Tools::setToolsFrame(bool* arr) {
  Serial.print("tools:  ");
  for (int i = 0; i < TOOLS_COUNT; i++) {
    if(arr[i]==1){
        this->toolsFrame[i]=!this->toolsFrame[i];}
    Serial.print(this->toolsFrame[i]);
    Serial.print(" ");
  }
  Serial.println();
}

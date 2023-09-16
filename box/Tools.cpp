#include "Tools.h"

Tools::Tools(int latchPin, int clockPin, int dataPin) {
  this->toolPins[LatchPin] = latchPin;
  this->toolPins[ClockPin] = clockPin;
  this->toolPins[DataPin] = dataPin;
}
void Tools::init() {
  // for (int i = 0; i < SHIFTREGISTER; i++) {
  //   pinMode(toolPins[i], OUTPUT);  //set tool pins to be Output pins
  // }
  pinMode(33,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(17,OUTPUT);
  log_i("Done initialize tools %d" ,2);
}
void Tools::update() {
  // Serial.print("Tools: ");
  // for (int i = 0; i < TOOLS_COUNT; i++) {
  //   Serial.print(this->toolsFrame[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();
  this->registerWrite(this->toolsFrame);
}

void Tools::registerWrite(bool* arr) {
  byte bitsToSend = 0;
  for (int i = 0; i < TOOLS_COUNT; i++) bitWrite(bitsToSend, i, arr[i]);
  digitalWrite(33, LOW);
  shiftOut(17, 32, MSBFIRST, bitsToSend);
  digitalWrite(33, HIGH);
  vTaskDelay(10);
}

bool* Tools::getToolsFrame() {
  return this->toolsFrame;
}

void Tools::setToolsFrame(bool* arr) {
  for (int i = 0; i < TOOLS_COUNT; i++) {
    Serial.print(this->toolsFrame[i]);
    Serial.print("");
    if (arr[i] == 1) {
      this->toolsFrame[i] = !this->toolsFrame[i];
    }
  }
  Serial.println();
}

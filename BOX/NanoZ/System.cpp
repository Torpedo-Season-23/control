#include "System.h"


void System::init() {
 thrusters.init();
  tools.init();
  uartz.startUart();

}

void System::getData() {
  // Serial.print("Waiting to receive...");
  uartz.receiveFrame();
  uartz.extractData(thrusters.thrustersFrame, tools.toolsFrame);

}

void System::setData() {
  thrusters.applySignal();
  tools.applySignal();
}
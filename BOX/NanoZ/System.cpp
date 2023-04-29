#include "System.h"


void System::init() {
  tools.init();
  uartz.startUart();
  thrusters.init();
}

void System::getData() {
   Serial.print("Waiting to receive...");
  uartz.receiveFrame();
  uartz.extractData(thrusters.thrustersFrame, tools.toolsFrame, thruster.brakesFrame);

}

void System::setData() {
  //uartz.sendFrame();
  thrusters.applySignal();
  tools.applySignal();
}

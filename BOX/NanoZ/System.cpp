#include "System.h"


void System::init() {
<<<<<<< HEAD
  thrusters.init();
  tools.init();
  uartz.startUart();
=======
 thrusters.init();
  tools.init();
  uartz.startUart();

>>>>>>> tested_system
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
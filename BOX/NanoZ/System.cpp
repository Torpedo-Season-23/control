#include "System.h"


void System::init() {
  tools.init();
  uartz.startUart();
  thrusters.init();

}

void System::getData() {
  //  Serial.print("Waiting to receive...");
//  long int x = millis();
  uartz.receiveFrame();

//  long int y =  millis();

  // Serial.println(y);

  uartz.extractData(thrusters.thrustersFrame, tools.toolsFrame);
  // long int z = millis() - y ;

  // Serial.println(z);

}

void System::setData() {
  //uartz.sendFrame();

  thrusters.applySignal();
  tools.applySignal();
}

#include "System.h"

System s;

void setup() {
  Serial.begin(115200);
  s.init();
}

void loop() {
  // s.receiveData();
  s.activateUART();
  // s.sendData();

//   s.receiveData();
//  // s.activateUART();
//   //Read Here From Converters
//   s.sendData();
}


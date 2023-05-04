#include "System.h"
#include "config.h"

System s;

void setup() {
  Serial.begin(115200);
  s.init();
}

void loop() {
  s.receiveData();
  s.activateUART();
  s.sendData();
}

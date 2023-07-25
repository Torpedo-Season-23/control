#include "System.h"

System sys;

void setup() {
  Serial.begin(9600);
  sys.init();
}

void loop() {
  sys.receiveData();
  sys.getData();
  sys.setData();
  sys.sendData();
}

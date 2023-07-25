#include "System.h"

System sys;

void setup() {
  Serial.begin(9600);
  sys.init();
}

void loop() {
  long current = millis();
  sys.getData();
  sys.setData();
  //delay(20);
}

#include "System.h"

System sys;

void setup() {
  Serial.begin(115200);
  sys.init();
}

void loop() {
  long current= millis();
  sys.getData();
  sys.setData();
  delay(20);
}

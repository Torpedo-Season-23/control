#include "System.h"

System sys;

void setup() {
  Serial.begin(115200);
  sys.init();
}

void loop() {
  sys.getData();
  sys.setData();
}

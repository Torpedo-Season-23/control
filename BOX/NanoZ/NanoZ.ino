#include "System.h"

System sys;

void setup() {
  Serial.begin(115200);
  sys.init();
}

void loop() {
  Serial.println("gggggggg");
  sys.getData();
  sys.setData();
}

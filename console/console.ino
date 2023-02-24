#include "lib/temp/System.h"

PS3GamePad controller;
System s(&controller);

void setup() {
  Serial.begin(115200);
  Serial.println("Setup");
  s.init();
}

void loop() {
  s.update();
}
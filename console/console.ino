#include "System.h"


Xbox controller;
System s(&controller);
void setup() {
  Serial.begin(115200);
  s.Init();
}

void loop() {
  s.Update();
}

#include "System.h"


PSGamepad controller;
System s(&controller);
void setup() {
  Serial.begin(115200);
  s.Init();
}

void loop() {
  s.Update();
}
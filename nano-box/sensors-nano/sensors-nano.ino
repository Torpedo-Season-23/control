#include "lib/code/snano.h"

SNano snano;

void setup() {
  Serial.begin(BAUD_RATE);
  snano.init();
}

void loop() {
  snano.update();
}
#include "lib/code/enano.h"
ENANO enano;
void setup() {
  Serial.begin(BAUD_RATE);
  enano.init();
}

void loop() {
  enano.update();
}

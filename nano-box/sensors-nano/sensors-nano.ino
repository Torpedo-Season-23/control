#include "lib/code/snano.h"

SNano snano;

void setup() {
  snano.init();
  attachInterrupt(digitalPinToInterrupt(SENSORS_INTERRUPT_PIN), handle, LOW);
}

void loop() {
  snano.update();
  snano.receive();
}

void handle() {
  snano.send();
}
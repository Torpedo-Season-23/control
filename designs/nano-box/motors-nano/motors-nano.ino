#include "lib/code/mnano.h"

MNano mnano;

void setup() {
  mnano.init();
}

void loop() {
  mnano.update();
}
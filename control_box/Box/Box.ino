#include "TorpedoMPU.h"


TorpedoMPU tmpu;

void setup() {
  Serial.begin(115200);

  tmpu.start();
  tmpu.check();
}

void loop() {

  tmpu.calculate();

}

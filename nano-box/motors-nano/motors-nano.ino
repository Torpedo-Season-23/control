#include "lib/code/mnano.h"

MNANO mnano;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  mnano.init();
}

void loop() {
  blinkLed();
  mnano.update();
}

void blinkLed() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

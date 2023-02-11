#include "lib/code/euart.h"

EUART euart;

void setup() {
  euart.init();
}

void loop() {
  blinkLed();
  euart.send();
  euart.recieve();
}

void blinkLed() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
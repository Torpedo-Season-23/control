#include "lib/code/enano.h"

ENANO enano;
long currentTime;

void setup() {
  enano.init();
}

void loop() {
  currentTime = millis();
  blinkLed();
  enano.update();
  if (millis() - currentTime > GET_SENSORS_TIME)
    enano.getSensors();
}

void blinkLed() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
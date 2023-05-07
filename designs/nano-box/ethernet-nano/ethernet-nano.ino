#include "lib/code/enano.h"

ENano enano;
long currentTime;

void setup() {
  pinMode(SENSOR_INTERRUPT_PIN, OUTPUT);
  enano.init();
}

void loop() {
  currentTime = millis();
  enano.update();
  if (millis() - currentTime > GET_SENSORS_TIME)
    enano.getSensors();
}
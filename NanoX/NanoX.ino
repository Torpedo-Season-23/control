#include "Converter.h"
#include <Servo.h>

Servo servos[6];

Converter myConverter;
long current;

int servopins[6] = { 3, 5, 6, 9, 10, 11 };

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servopins[i]);
  }
  delay(2000);
  current = millis();
}

void loop() {
  if (current - 5000 < 0) {  //run for 5 seconds then stops
    for (int i = 0; i < 6; i++) {
      servos[i].write(1900);
    }
  }
  myConverter.print_data();
}
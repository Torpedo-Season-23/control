#include "Thrusters.h"

void Thrusters::init() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].setPeriodHertz(100); ;
    Motors[i].attach(motorPins[i]);
  }
  delay(2000);
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].writeMicroseconds(MOT_ZERO_SPEED);
  }
  
}


//set speeds to Motors
void Thrusters::update() {
  // Serial.print("Motors : ");
  for (int i = 0; i < MOTORS_COUNT; i++) {
  // Serial.print(thrustersFrame[i]);
  // Serial.print(" ");
    Motors[i].writeMicroseconds(thrustersFrame[i]);
  }
  // Serial.println();
}

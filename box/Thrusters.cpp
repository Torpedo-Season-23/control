#include "Thrusters.h"

void Thrusters::init() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].setPeriodHertz(50); ;
    Motors[i].attach(motorPins[i]);
    Motors[i].writeMicroseconds(MOT_ZERO_SPEED);
  }
  delay(1000);
}


//set speeds to Motors
void Thrusters::update() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].writeMicroseconds(thrustersFrame[i]);
  }
}

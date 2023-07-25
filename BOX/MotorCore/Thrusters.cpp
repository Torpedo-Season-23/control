#include "Thrusters.h"

void Thrusters::init() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].attach(motorPins[i]);
    Motors[i].writeMicroseconds(MOT_ZERO_SPEED);
  }
  delay(1000);
}


//set speeds to Motors
void Thrusters::applySignal() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    //apply speeds to thrusters
    Motors[i].writeMicroseconds(thrustersFrame[i]);
  }
}

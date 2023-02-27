#include "Thrusters.h"



void Thrusters::init() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].attach(motorPins[i]);
    Motors[i].writeMicroseconds(MOT_ZERO_SPEED);  //stop speed 1500
  }
  delay(2000);
}


//set signals to Motors
void Thrusters::apply_signal(int *thrustersSpeeds) {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    //apply speeds to thrusters
     Motors[i].writeMicroseconds(thrustersSpeeds[i]);
  }
}


//prepare motor speeds and exponants to be sent to motors
void Thrusters::prep_And_apply_signal() {
  int thrustersSpeeds[MOTORS_COUNT];
  for (int i = 0; i < MOTORS_COUNT; i++) { 
    int dir = (this->thrustersFrame[i] == 1) ? 1 : -1;
    int speedChange = map(this->thrustersFrame[i + MOTORS_COUNT], 0, 255, 0, 400);
    int speedValue = 1500 + dir * speedChange;
    thrustersSpeeds[i] = speedValue;

  }

  this->apply_signal(thrustersSpeeds);
}


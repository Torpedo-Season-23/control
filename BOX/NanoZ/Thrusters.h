#ifndef Thrusters_H
#define Thrusters_H
#include "Config.h"
#include <Servo.h>



class Thrusters{
  // motor pins
  const int motorPins[MOTORS_COUNT] =  {0};
  Servo Motors[MOTORS_COUNT];

  public:
  uint8_t *thrustersFrame;
  void init();
  void apply_signal(int *thrustersSpeeds);
  void prep_And_apply_signal();
};


#endif
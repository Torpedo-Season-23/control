#ifndef Thrusters_H
#define Thrusters_H
#include "Config.h"
#include <Servo.h>


class Thrusters {
  // motor pins
  const int motorPins[MOTORS_COUNT] = { 0 };
  Servo Motors[MOTORS_COUNT];

public:
  uint16_t *thrustersFrame;
  void init();
  void applySignal();
};


#endif
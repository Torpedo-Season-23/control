#ifndef Thrusters_H
#define Thrusters_H
#include "Config.h"
#include "Servo.h"

class Thrusters {
  // motor pins
  const uint8_t motorPins[MOTORS_COUNT] = { 14,15,16,17,18,20 };
  Servo Motors[MOTORS_COUNT];

public:
  uint16_t thrustersFrame[MOTORS_COUNT];
  void init();
  void applySignal();
};


#endif

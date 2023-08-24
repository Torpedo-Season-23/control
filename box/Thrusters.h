#ifndef Thrusters_H
#define Thrusters_H
#include "Config.h"
#include <ESP32Servo.h>

class Thrusters {
  const uint8_t motorPins[MOTORS_COUNT] = { 18,5,16,17,18,20 };
  Servo Motors[MOTORS_COUNT];
public:
  uint16_t thrustersFrame[MOTORS_COUNT];
  void init();
  void update();
};


#endif

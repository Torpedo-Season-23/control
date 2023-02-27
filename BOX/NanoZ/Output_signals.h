#ifndef OUT_H
#define OUT_H

#include <Arduino.h>
#include <Servo.h>

#define MOTORS_COUNT  6
#define TOOLS_COUNT  8
#define MOT_ZERO_SPEED 1500

extern Servo Motors[MOTORS_COUNT]; 

class Thrusters{
  // motor pins
  const int motorPins[MOTORS_COUNT] =  {0};
  public:
  uint8_t *thrustersFrame;
  void init();
  void apply_signal(int *thrustersSpeeds);
  void prep_And_apply_signal();
};


class Tools{
  // first 5 are Grippers pins, last 3 lights pins 
  const int toolPins[TOOLS_COUNT] = {0};
  public:
  uint8_t *tool_frame;
  void init();
  void apply_signal();
};
#endif

#ifndef Thrusters_H
#define Thrusters_H
#include "Config.h"
#include "Servo.h"


class Thruster {
public:
  Servo motor;
  uint16_t currentValue;
  long lastUpdatedTime;
  void initialize(uint8_t pin);
  void setSignal(uint16_t value);
private:
  void writeSignal();
  void handleBrake(uint16_t value);
};

class Thrusters {
  // motor pins
  const int motorPins[MOTORS_COUNT] = { 3,5,6,9,10,11 };
  Thruster Motors[MOTORS_COUNT];

public:
  uint16_t thrustersFrame[MOTORS_COUNT];
  void init();
  void applySignal();
};


#endif

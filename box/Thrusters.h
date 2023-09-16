#ifndef Thrusters_H
#define Thrusters_H
#include "Config.h"
#include <ESP32Servo.h>


// 2 ,4  ,
class Thrusters {
  const uint8_t motorPins[MOTORS_COUNT] = {  16, 25, 26, 27 ,2, 4};
  Servo Motors[MOTORS_COUNT];
public:
  uint16_t thrustersFrame[MOTORS_COUNT];
  void init();
  void update();
};



//fr 27
//fl 16
//br 25
//bl 26
//uf 4 
//ub 2

#endif

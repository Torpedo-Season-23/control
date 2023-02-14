#ifndef _MAPPER_H_
#define _MAPPER_H_

#include "config.h"

class MotorsMapper {
 private:
  uint8_t data[MOTORS_FRAME_SIZE];
  uint16_t speed[MOTOR_COUNT];
  uint8_t exponent[EXPONENT_COUNT];
  DIRECTION direction;
  void setSpeed();
  void setExponent();
  void setDirection();

 public:
  MotorsMapper();
  void setData(uint8_t frame[MOTORS_FRAME_SIZE]);
  uint16_t* getSpeed();
  uint8_t* getExponent();
  DIRECTION getDirection();
};

#ifndef _MAPPER_CPP_
#include "mapper.cpp"
#endif

#endif
#ifndef _MOTION_H_
#define _MOTION_H_

#include "config.h"
#include "servo_rov_motor.h"

class Motion {
 protected:
  DIRECTION direction;
  virtual void forward() = 0;
  virtual void backward() = 0;
  virtual void left() = 0;
  virtual void right() = 0;
  virtual void momentLeft() = 0;
  virtual void momentRight() = 0;
  virtual void up() = 0;
  virtual void down() = 0;
  virtual void generic() = 0;

 public:
  virtual void init() = 0;
  virtual void reset() = 0;
  virtual void update() = 0;
  virtual void setDirection(DIRECTION direction) = 0;
  virtual void setSpeed(uint16_t *speed) = 0;
  virtual void setExponent(uint8_t *exponent) = 0;
  virtual void move() = 0;
  virtual void stop() = 0;
};

#endif
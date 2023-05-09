#ifndef _SERVO_ROV_MOTOR_H_
#define _SERVO_ROV_MOTOR_H_

#include "../Servo/Servo.h"

#include "../SoftStart/softstart.h"
#include "config.h"

class ServoROVMotor {
 protected:
  unsigned char pin;
  MOTOR_ORIENTATION type;
  DIRECTION direction;
  uint16_t speed;
  float exponent;
  Servo *servo;
  bool softStart;
  virtual void setSpeed(uint16_t speed);
  virtual void apply(uint16_t previousSpeed);

 public:
  ServoROVMotor(unsigned char pin, MOTOR_ORIENTATION type);
  virtual void init();
  virtual void clockWise(uint16_t speed);
  virtual void antiClockWise(uint16_t speed);
  virtual void setExponent(float exponent);
  virtual void putSpeed(uint16_t speed);
  virtual MOTOR_ORIENTATION getType();
  virtual uint16_t getSpeed();
  virtual void reset();
  virtual void stop();
  virtual void update();
};

#ifndef _SERVO_ROV_MOTOR_CPP_
#include "servo_rov_motor.cpp"
#endif

#endif
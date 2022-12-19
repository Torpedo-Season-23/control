#ifndef _SERVO_ROV_MOTOR_H_
#define _SERVO_ROV_MOTOR_H_

#include "config.h"

class ServoROVMotor {
   protected:
    unsigned char pin;
    DIRECTION direction;
    float speed;
    float factor;

   public:
    ServoROVMotor(unsigned char pin);
    virtual void init();
    virtual void reset();
    virtual void clockWise();
    virtual void antiClockWise();
    virtual void stop();
    virtual void setDirection(DIRECTION direction);
    virtual void setSpeed(float speed);
    virtual void setFactor(float factor);
};

#ifndef _SERVO_ROV_MOTOR_CPP_
#include "servo_rov_motor.cpp"
#endif

#endif
#ifndef _SERVO_ROV_MOTOR_H_
#define _SERVO_ROV_MOTOR_H_

#include "config.h"

class ServoROVMotor {
   public:
    unsigned char pin;
    DIRECTION direction;
    float speed;
    float factor;
    ServoROVMotor(unsigned char pin);
    virtual void init() = 0;
    virtual void reset() = 0;
    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual void setDirection(DIRECTION direction);
    virtual void setSpeed(float speed);
    virtual void setFactor(float factor);
};

#endif
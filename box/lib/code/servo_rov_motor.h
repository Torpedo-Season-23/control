#ifndef _SERVO_ROV_MOTOR_H_
#define _SERVO_ROV_MOTOR_H_

#include "config.h"
#include <Servo.h>

class ServoROVMotor {
   protected:
    unsigned char pin;
    MOTOR_ORIENTATION type;
    DIRECTION direction;
    float speed;
    Servo *servo;
    virtual void setSpeed(float speed);

   public:
    ServoROVMotor(unsigned char pin, MOTOR_ORIENTATION type);
    virtual void init();
    virtual void clockWise(float speed);
    virtual void antiClockWise(float speed);
    virtual void stop();
};

#ifndef _SERVO_ROV_MOTOR_CPP_
#include "servo_rov_motor.cpp"
#endif

#endif
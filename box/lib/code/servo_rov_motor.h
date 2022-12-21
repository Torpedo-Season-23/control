#ifndef _SERVO_ROV_MOTOR_H_
#define _SERVO_ROV_MOTOR_H_

#include "config.h"
#include <Servo.h>

class ServoROVMotor {
   protected:
    unsigned char pin;
    MOTOR_ORIENTATION type;
    DIRECTION direction;
    uint8_t speed;
    Servo *servo;
    virtual void setSpeed(uint8_t speed);

   public:
    ServoROVMotor(unsigned char pin, MOTOR_ORIENTATION type);
    virtual void init();
    virtual void clockWise(uint8_t speed);
    virtual void antiClockWise(uint8_t speed);
    virtual void reset();
    virtual void stop();
};

#ifndef _SERVO_ROV_MOTOR_CPP_
#include "servo_rov_motor.cpp"
#endif

#endif
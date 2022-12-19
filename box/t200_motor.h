#ifndef _T200_MOTOR_H_
#define _T200_MOTOR_H_

#include "servo_rov_motor.h"

class T200Motor : public ServoROVMotor {
   public:
    T200Motor(unsigned char pin, float factor);
    virtual void init();
    virtual void forward();
    virtual void backward();
    virtual void reset();
};

#endif

#ifndef _T100_MOTOR_H_
#define _T100_MOTOR_H_

#include "servo_rov_motor.h"

class T100Motor : public ServoROVMotor {
   public:
    T100Motor(unsigned char pin, float factor);
    virtual void init();
    virtual void forward();
    virtual void backward();
    virtual void reset();
};

#endif

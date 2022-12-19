#ifndef _T100_MOTOR_H_
#define _T100_MOTOR_H_

#include "servo_rov_motor.h"

class T100Motor : public ServoROVMotor {
   public:
    T100Motor(unsigned char pin);
};

#ifndef _T100_MOTOR_CPP_
#include "t100_motor.cpp"
#endif

#endif

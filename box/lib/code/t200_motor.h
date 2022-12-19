#ifndef _T200_MOTOR_H_
#define _T200_MOTOR_H_

#include "servo_rov_motor.h"

class T200Motor : public ServoROVMotor {
   public:
    T200Motor(unsigned char pin);
};

#ifndef _T200_MOTOR_CPP_
#include "t200_motor.cpp"
#endif

#endif

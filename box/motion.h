#ifndef _MOTION_H_
#define _MOTION_H_

#include "config.h"
#include "t100_motor.h"
#include "t200_motor.h"

class Motion {
    private:
        Motor *motors[MOTOR_COUNT];
    
    public:
        Motion();
        void init();
        void reset();
        void move(DIRECTION direction);
        void setSpeed(int speed);
};

#endif
#ifndef _MOTION_H_
#define _MOTION_H_

#include "config.h"
#include "t100_motor.h"
#include "t200_motor.h"

class Motion {
   private:
    ServoROVMotor *motors[MOTOR_COUNT];
    void forward();
    void backward();
    void left();
    void right();
    void momentLeft();
    void momentRight();
    void up();
    void down();
    void stop();

   public:
    Motion();
    void init();
    void reset();
    void move(DIRECTION direction);
    void setSpeed(int speed);
};

#ifndef _MOTION_CPP_
#include "motion.cpp"
#endif

#endif
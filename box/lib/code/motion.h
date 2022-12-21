#ifndef _MOTION_H_
#define _MOTION_H_

#include "config.h"
#include "helper.h"
#include "t100_motor.h"
#include "t200_motor.h"

class Motion {
   private:
    ServoROVMotor *motors[MOTOR_COUNT];
    uint8_t *speed;
    DIRECTION direction;
    void forward();
    void backward();
    void left();
    void right();
    void momentLeft();
    void momentRight();
    void up();
    void down();
    void display();

   public:
    Motion();
    void init();
    void reset();
    void update();
    void setDirection(DIRECTION direction);
    void setSpeed(uint8_t *speed);
    void move();
    void stop();
};

#ifndef _MOTION_CPP_
#include "motion.cpp"
#endif

#endif
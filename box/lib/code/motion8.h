#ifndef _MOTION8_H_
#define _MOTION8_H_

#include "config.h"
#include "helper.h"
#include "motion.h"
#include "t100_motor.h"
#include "t200_motor.h"

class Motion8 : public Motion {
   private:
    ServoROVMotor *motors[MOTOR_COUNT];
    uint16_t speed[MOTOR_COUNT];
    uint8_t exponent[EXPONENT_COUNT];
    virtual void forward();
    virtual void backward();
    virtual void left();
    virtual void right();
    virtual void momentLeft();
    virtual void momentRight();
    virtual void up();
    virtual void down();
    virtual void generic();
    virtual void display();

   public:
    Motion8();
    virtual void init();
    virtual void reset();
    virtual void update();
    virtual void setDirection(DIRECTION direction);
    virtual void setSpeed(uint16_t *speed);
    virtual void setExponent(uint8_t *exponent);
    virtual void move();
    virtual void stop();
};

#ifndef _MOTION8_CPP_
#include "motion8.cpp"
#endif

#endif
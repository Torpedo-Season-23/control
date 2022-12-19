#ifndef _ROV_H_
#define _ROV_H_

#include "config.h"
#include "ethernet.h"
#include "motion.h"
#include "navigation.h"

class ROV {
   private:
    DIRECTION direction;
    SensorsManager *sensorsManager;
    Motion *motion;
    Communication *communication;

   public:
    ROV();
    void init();
    void update();
    void reset();
    void move(DIRECTION direction);
    void setSpeed(int speed);
    void send();
    void recieve();
};

#ifndef _ROV_CPP_
#include "rov.cpp"
#endif

#endif
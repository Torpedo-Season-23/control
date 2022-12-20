#ifndef _ROV_H_
#define _ROV_H_

#include "config.h"
#include "ethernet.h"
#include "motion.h"
#include "sensors_manager.h"
#include "mapper.h"

class ROV {
   private:
    DIRECTION direction;
    float speed;
    uint8_t *accessories;
    SensorsManager *sensorsManager;
    Motion *motion;
    Communication *communication;

   public:
    ROV();
    void init();
    void update();
    void reset();
    void setSpeed(int speed);
    void send();
    void recieve();
};

#ifndef _ROV_CPP_
#include "rov.cpp"
#endif

#endif
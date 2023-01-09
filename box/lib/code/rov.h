#ifndef _ROV_H_
#define _ROV_H_

#include "accessories.h"
#include "config.h"
#include "ethernet.h"
#include "mapper.h"
#include "motion8.h"
#include "sensors_manager.h"

class ROV {
   private:
    uint8_t *data;
    SensorsManager *sensorsManager;
    Motion *motion;
    Communication *communication;
    Accessories *accessories;
    Mapper *mapper;
    void prepareData();
    void setMotion();
    void setAccessories();
    void setSensors();

   public:
    ROV();
    void init();
    void update();
    void reset();
};

#ifndef _ROV_CPP_
#include "rov.cpp"
#endif

#endif
#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

#include "config.h"
#include "imu_sensor.h"
#include "pressure_sensor.h"

class Navigation {
   private:
    Sensor *sensors[SENSOR_COUNT];
    bool working;

   public:
    Navigation();
    void init();
    void update();
    void reset();
    void toggleWorking();
};

#ifndef _NAVIGATION_CPP_
#include "navigation.cpp"
#endif

#endif
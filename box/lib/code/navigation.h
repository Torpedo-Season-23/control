#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

#include "config.h"
#include "current_sensor.h"
#include "imu_sensor.h"
#include "pressure_sensor.h"

class SensorsManager {
   private:
    Sensor *sensors[SENSOR_COUNT];
    Sensor *currentSensors[CURRENT_SENSOR_COUNT];
    bool working;

   public:
    SensorsManager();
    void init();
    void update();
    void reset();
    void toggleWorking();
};

#ifndef _NAVIGATION_CPP_
#include "navigation.cpp"
#endif

#endif
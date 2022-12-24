#ifndef _SENSORS_MANAGER_H_
#define _SENSORS_MANAGER_H_

#include "config.h"
#include "current_sensor.h"
#include "mpu_sensor.h"
#include "pressure_sensor.h"

class SensorsManager {
   private:
    Sensor **sensors;
    uint8_t sensorsData[SENSORS_DATA_SIZE];
    bool working;

   public:
    SensorsManager();
    void init();
    void update();
    void reset();
    void startWorking();
    void stopWorking();
    void toggleSensorWorking(SENSOR_TYPE sensor);
    void toggleWorking();
    uint8_t *getSensorsData();
    void display();
};

#ifndef _SENSORS_MANAGER_CPP_
#include "sensors_manager.cpp"
#endif

#endif
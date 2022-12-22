#ifndef _SENSORS_MANAGER_H_
#define _SENSORS_MANAGER_H_

#include "config.h"
#include "current_sensor.h"
#include "imu_sensor.h"
#include "pressure_sensor.h"

class SensorsManager {
   private:
    Sensor **sensors;
    Sensor **currentSensors;
    uint8_t sensorsData[SENSORS_DATA_SIZE];
    bool working;
    void prepareSensorsData();

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
};

#ifndef _SENSORS_MANAGER_CPP_
#include "sensors_manager.cpp"
#endif

#endif
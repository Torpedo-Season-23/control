#ifndef _IMU_SENSOR_H_
#define _IMU_SENSOR_H_

#include <Wire.h>

#include "config.h"
#include "sensor.h"

class IMUSensor : public Sensor {
   private:
    uint8_t accelX;
    uint8_t accelY;
    uint8_t accelZ;
    uint8_t gyroX;
    uint8_t gyroY;
    uint8_t gyroZ;
    uint8_t magX;
    uint8_t magY;
    uint8_t magZ;
    uint8_t temp;
    virtual void display();

   public:
    IMUSensor();
    virtual void init();
    virtual void update();
    virtual void reset();
};

#ifndef _IMU_SENSOR_CPP_
#include "imu_sensor.cpp"
#endif

#endif
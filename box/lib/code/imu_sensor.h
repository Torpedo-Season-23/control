#ifndef _IMU_SENSOR_H_
#define _IMU_SENSOR_H_

#include <Wire.h>

#include "../MPU6050/MPU6050.h"
#include "config.h"
#include "sensor.h"

class MPU6050Sensor : public Sensor {
   private:
    int16_t accelX;
    int16_t accelY;
    int16_t accelZ;
    int16_t gyroX;
    int16_t gyroY;
    int16_t gyroZ;
    int16_t magX;
    int16_t magY;
    int16_t magZ;
    int16_t temp;
    unsigned long currentTime;
    unsigned long previousTime;
    MPU6050 *mpu;
    virtual void display();

   public:
    MPU6050Sensor();
    virtual void init();
    virtual void update();
    virtual void reset();
};

#ifndef _IMU_SENSOR_CPP_
#include "imu_sensor.cpp"
#endif

#endif
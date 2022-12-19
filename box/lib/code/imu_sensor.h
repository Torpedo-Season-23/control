#ifndef _IMU_SENSOR_H_
#define _IMU_SENSOR_H_

#include <Wire.h>
#include "sensor.h"
#include "config.h"

class IMUSensor : public Sensor {
  private:
    unsigned char scl;
    unsigned char sda;
    float accel_x;
    float accel_y;
    float accel_z;
    float gyro_x;
    float gyro_y;
    float gyro_z;
    float mag_x;
    float mag_y;
    float mag_z;
    float temp;
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
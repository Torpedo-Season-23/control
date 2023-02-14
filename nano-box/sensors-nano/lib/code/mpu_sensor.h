#ifndef _IMU_SENSOR_H_
#define _IMU_SENSOR_H_

#include <Wire.h>

#include "../MPU6050/MPU6050.h"
#include "config.h"
#include "sensor.h"

class MPU6050Sensor : public Sensor {
 private:
  MPU6050* mpu;
  int16_t accelX;
  int16_t accelY;
  int16_t accelZ;
  int16_t gyroX;
  int16_t gyroY;
  int16_t gyroZ;
  uint8_t data[MPU_FRAME_SIZE];
  unsigned long currentTime;
  unsigned long previousTime;
  virtual void display();

 public:
  MPU6050Sensor();
  virtual void init();
  virtual void update();
  virtual void reset();
  uint8_t* getData();
};

#ifndef _IMU_SENSOR_CPP_
#include "mpu_sensor.cpp"
#endif

#endif
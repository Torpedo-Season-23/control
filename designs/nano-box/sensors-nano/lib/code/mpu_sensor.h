#ifndef _IMU_SENSOR_H_
#define _IMU_SENSOR_H_

#include <Wire.h>

#include "../Adafruit_MPU6050/Adafruit_MPU6050.h"
#include "config.h"
#include "sensor.h"

class MPU6050Sensor : public Sensor {
 private:
  Adafruit_MPU6050* mpu;
  uint8_t data[MPU_FRAME_SIZE];
  unsigned long currentTime;
  unsigned long previousTime;

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
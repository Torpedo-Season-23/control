#ifndef __IMU_H
#define __IMU_H
#include "ISensor.h"
#include <MPU6050_light.h>


class IMU : public ISensor {
  int *angles;
  int temp;
  MPU6050 mpu;
  int readRate;
  unsigned long timer;
public:
  IMU();
  IMU(int rate);
  void init() override;
  void update() override;
  void display() override;
  int *getAngles();
  int getTemprature();
};


#endif
#ifndef __IMU_H
#define __IMU_H
#include "ISensor.h"
#include <MPU6050_light.h>


class IMU : public ISensor {
  int *angles;
  int temp;
  MPU6050 *mpu;
  int readRate;
  unsigned long timer;
  signed long offset_x;
  signed long offset_y;
  signed long offset_z;

public:
  IMU(){
    this->mpu=new MPU6050(Wire);
    this->angles = new int[3];
    this->temp = 0;
    this->readRate = 1000;
  }
  void init() override;
  void update() override;
  void display() override;
  int *getAngles();
  int getTemprature();
};


#endif
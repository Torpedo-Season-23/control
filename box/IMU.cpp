#include "IMU.h"

IMU::IMU():mpu(Wire) {
  
  this->angles = new int[3];
  this->temp = 0;
  this->readRate=1000;
}
IMU::IMU(int rate):mpu(Wire){
  this->angles = new int[3];
  this->temp = 0;
  this->readRate=rate;
}



void IMU::init(){
  Wire.begin();
  byte status = this->mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  if (status != 0) {
    Serial.println(F("IMU sensor doesn't connected!! "));
  }
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  this->mpu.calcOffsets();  // gyro and accelero
  Serial.println("Done!\n");
}

void IMU::update() {
  this->mpu.update();
  if ((millis() - this->timer) > this->readRate) {  // print data every 10ms
    this->angles[0]=this->mpu.getAngleX();
    this->angles[1]=this->mpu.getAngleY();
    this->angles[2]=this->mpu.getAngleZ();
    this->timer = millis();
  }
}

int * IMU::getAngles() {
  return this->angles;
}

int IMU::getTemprature() {
  return this->temp;
}

void IMU::display() {
  Serial.print("ANGLES =    X: ");
  Serial.print(this->angles[2]);
  Serial.print("\tY: ");
  Serial.print(this->angles[1]);
  Serial.print("\tZ: ");
  Serial.println(this->angles[0]);
  Serial.print("temperature = ");
  Serial.print(this->temp);
  Serial.println(" °C");
//  Serial.println("************************************");
}

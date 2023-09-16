#include "IMU.h"



void IMU::init() {
  Wire.begin();
  Serial.println("here");
  byte status = this->mpu->begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  if (status != 0) {
    Serial.println(F("IMU sensor doesn't connected!! "));
  }
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  this->mpu->calcOffsets();  // gyro and accelero
  Serial.println("Done!\n");
  mpu->update();
  this->offset_x=mpu->getAngleX();
  this->offset_y=mpu->getAngleY();
  this->offset_z=mpu->getAngleZ();
}

void IMU::update() {
  mpu->update();
  if((millis()-timer)>10){ // print data every 10ms
	this->angles[0]=mpu->getAngleX()-this->offset_x;
	this->angles[1]=mpu->getAngleY()-this->offset_y;
	this->angles[2]=mpu->getAngleZ()-this->offset_z;
  this->temp=this->mpu->getTemp();
	timer = millis();  
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
  Serial.print(this->angles[0]);
  Serial.print("\tY: ");
  Serial.print(this->angles[1]);
  Serial.print("\tZ: ");
  Serial.println(this->angles[2]);
  Serial.print("temperature = ");
  Serial.print(this->temp);
  Serial.println(" °C");
  Serial.println("************************************");
}
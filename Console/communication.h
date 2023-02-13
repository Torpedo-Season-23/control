#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Arduino.h>
#include <UIPEthernet.h>

#define receivedFrameSize 10  //10 bytes, IMU: 3*2bytes, Pressure: 1*2bytes, Current: 2*1bytes respectively
#define sentFrameSize 13      //13 bytes, Thrusters: 6*2bytes, Accessories: 1 byte respectively (will be changed if softstart is added)

#define SENSORS 6
#define IMU 3
#define CURRENT 2
#define PRESSURE 1

#define THRUSTERS 6
#define ACCESSORIES 4  //will be modified (1 byte anyways)


void comm_init();

void receiveData(uint8_t* receivedFrame);

void getSensors(uint8_t* receivedFrame, int16_t* sensors);

void prepareData(uint8_t* accessories, double* thrusters, uint8_t* sentFrame);

void sendData(uint8_t* sentFrame);



#endif
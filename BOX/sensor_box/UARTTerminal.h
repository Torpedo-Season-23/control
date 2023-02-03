#ifndef UART_TERMINAL_H
#define UART_TERMINAL_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#define ANGLE_INDEX 0
#define PRESSURE_INDEX ANGLE_INDEX+3*2

struct sensorsData{
  int IMUangles[3];
  int pressure;
};

void initializeUART();
void setIMUAngles(int angles[3]);
void setPressure(int pressure);
void sendSensorData();
#endif

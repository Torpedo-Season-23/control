#include "Pressure.h"
#include "TorpedoMPU.h"
#include "UARTTerminal.h"

PressureSensor pressure;
TorpedoMPU IMU;

void setup(){
  Serial.begin(9600);
  initializeUART();
  pressure.init();
  //IMU.start();
}
uint8_t countPressure =0;
int ang[3]= {50,100,150};


void loop(){
  //Read From Sensors
  //pressure.update();
  //IMU.calculate();
  setIMUAngles(ang);
  for(int i= 0;i<3;i++)
    ang[i]++;
  setPressure(countPressure++);
  //pressure.pressure++;
  sendSensorData();
  Serial.println("Sent!");
  //delay(1000);
  //Send To Box.
}

#include "UARTTerminal.h"


struct sensorsData{
  int IMUangles[3];
  uint16_t pressure;
}uartData;

void initializeUART() {
  Serial2.begin(9600, SERIAL_8N1, RX, TX);
  uartData.IMUangles[0] = 0;
  uartData.pressure = 0;
}

void receiveFromUART(uint8_t* receivedFrame){
  while (Serial2.available()){
    byte x= Serial2.read();
    if(x != '<'){
      continue;
    }
    while (!Serial2.available());
    x= Serial2.read(); //index;
    uint8_t index= x;
    while (!Serial2.available());
    x= Serial2.read();
    if(x!= ',')
      continue;
    while (!Serial2.available());
    x= Serial2.read();
    uint8_t value= x;
    while (!Serial2.available());
    if(Serial2.read() != '>')continue;
    receivedFrame[index]= value;
  }
}
void receiveSensorData() {
  uint8_t receivedFrame[8];
  receiveFromUART(receivedFrame);
  uint8_t index= 0;
  for(uint8_t i= ANGLE_INDEX;i<ANGLE_INDEX+6;i+=2){
    uartData.IMUangles[index++]= (receivedFrame[i]<<8) | (receivedFrame[i+1]);
  }
  uartData.pressure= (receivedFrame[PRESSURE_INDEX]<<8) | (receivedFrame[PRESSURE_INDEX+1]);
  Serial.print("Angles: ");
  for(int i= 0;i<3;i++){
    Serial.print(uartData.IMUangles[i]);
    Serial.print(" , ");
  }
  Serial.print("Pressure ");
  Serial.println(uartData.pressure);
}

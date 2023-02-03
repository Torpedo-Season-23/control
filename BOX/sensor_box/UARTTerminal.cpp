#include "UARTTerminal.h"

struct sensorsData data;
SoftwareSerial softSerial(10,4);
void initializeUART(){
    softSerial.begin(9600);
    data.IMUangles[0]= 0;
    data.pressure= 0;
}
void setIMUAngles(int angles[3]){
    data.IMUangles[0]= angles[0];
    data.IMUangles[1]= angles[1];
    data.IMUangles[2]= angles[2];
}
void setPressure(int pressure){
   data.pressure= pressure;
}
void create_sending_frame(uint8_t* sendingFrame){
  uint8_t index= 0;
  for(int i=ANGLE_INDEX;i<ANGLE_INDEX+6;i+=2){
    sendingFrame[i]= highByte(data.IMUangles[index]);
    sendingFrame[i+1]= lowByte(data.IMUangles[index]);
    index++;
  }
  sendingFrame[PRESSURE_INDEX]= data.pressure >>8;
  sendingFrame[PRESSURE_INDEX+1]= data.pressure &0xFF;
}
void sendSensorData(){ 
    uint8_t sendingFrame[8];
    create_sending_frame(sendingFrame);
    for(uint8_t i= 0;i<8;i++){
      softSerial.write('<');
      softSerial.write(i);
      softSerial.write(',');
      softSerial.write(sendingFrame[i]);
      softSerial.write('>');
    }
    Serial.print("Angles: ");
  for(int i= 0;i<3;i++){
    Serial.print(data.IMUangles[i]);
    Serial.print(" , ");
  }
  Serial.print("Pressure ");
  Serial.println(data.pressure);
}

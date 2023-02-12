#include "UartX.h"
SoftwareSerial softSerial(9, 8);

void Nano_X::Start_Uart() {
  softSerial.begin(9600);
  IMU_Angles[0] = 0;
  pressure = 0;
}
void Nano_X::Set_IMU_Angles(int angles[3]) {
  IMU_Angles[0] =55;// angles[0];
  IMU_Angles[1] =25;// angles[1];
  IMU_Angles[2] =30;// angles[2];
}

void Nano_X::Set_Pressure(int Pressure) {
  pressure = Pressure;
}

void Nano_X::Prepare_frame(uint8_t Datafram[8]) {
  uint8_t Index = 0;
  for(int i=0;i>6;i++)
    Datafram[i]=i;
  /*for (int i = Imu_Angles_Index; i < Imu_Angles_Index; i + 2) {
    Datafram[i] = highByte(IMU_Angles[Index]);
    Datafram[i + 1] = lowByte(IMU_Angles[Index]);
    Index++;
  }*/

  Datafram[PRESSURE_index] = pressure >> 8;
  Datafram[PRESSURE_index + 1] = pressure & 0xFF;
}

void Nano_X::Send_Data() {
 // Serial.println("Sent...");
  
  uint8_t Datafram[8];
  Prepare_frame(Datafram);
  // softSerial.write('(');
  softSerial.write('(');
  softSerial.write(Datafram,8);
  softSerial.write(')');
  // softSerial.write(')');
}

void Nano_X::receive() {
  //Serial.print("Waiting to receive: ");
  //Serial.println(softSerial.available());
  uint8_t recFrame[3];
  while (1) {
    byte x;
    while (!softSerial.available());
    x = softSerial.read();
    if (x != '(') continue;
    while (!softSerial.available());
    for (int i = 0; i < 3; i++) {
      while (!softSerial.available());
      recFrame[i]= softSerial.read();
    }
    while (!softSerial.available());
    x = softSerial.read();
    if (x != ')') continue;
    noInterrupts();
    Serial.print("Frame is ");
    for(int i= 0;i<3;i++){
      Serial.print( recFrame[i]);
      Serial.print(" ");
    }
    Serial.println();
    interrupts();
    return;
  }
}

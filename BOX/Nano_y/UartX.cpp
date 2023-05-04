#include "UartX.h"
#include "config.h"
#include <Arduino.h>
SoftwareSerial softSerial(RX_Y, TX_Y);

long current;
Nano_X::Nano_X() {
  this->IMU_Angles[0] = 0;
  this->IMU_Angles[1] = 0;
  this->IMU_Angles[2] = 0;
  this->pressure = 0;
}
void Nano_X::Start_Uart() {
  softSerial.begin(9600);
  IMU_Angles[0] = 0;  //already initialized?
  pressure = 0;
}
void Nano_X::Set_IMU_Angles(int angles[3]) {
  IMU_Angles[0] = angles[0];
  IMU_Angles[1] = angles[1];
  IMU_Angles[2] = angles[2];
}

void Nano_X::Set_Pressure(int Pressure) {
  pressure = Pressure;
  Serial.println(pressure);
}

void Nano_X::Prepare_frame(uint8_t Dataframe[FRAME_SIZE]) {
  uint8_t Index = 0;
  for (int i = 0; i < 6; i += 2) {
    Dataframe[i] = highByte(IMU_Angles[Index]);
    Dataframe[i + 1] = lowByte(IMU_Angles[Index]);
    Index++;
  }

  Dataframe[PRESSURE_index] = pressure >> 8;
  Dataframe[PRESSURE_index + 1] = pressure & 0xFF;

  for(int i= 0;i<FRAME_SIZE ; i++)
  {
    Serial.print(Dataframe[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void Nano_X::Send_Data() {
  uint8_t Dataframe[FRAME_SIZE];
  Prepare_frame(Dataframe);
  softSerial.write('(');
  softSerial.write(Dataframe, FRAME_SIZE);
  softSerial.write(')');
}

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
  for (int i = 0; i < 8; i++) {
    this->leakage_values[i] = 0;
  }
}
void Nano_X::Start_Uart() {
  softSerial.begin(9600);
  IMU_Angles[0] = 0;  //already initialized?
  pressure = 0;
  leakage_values[0] = 10;  //debugging
}
void Nano_X::Set_IMU_Angles(int angles[3]) {
  IMU_Angles[0] = angles[0];
  IMU_Angles[1] = angles[1];
  IMU_Angles[2] = angles[2];
  // Serial.print("IMU ANGLES: ");
  // for(int i=0 ; i<3 ; i++)
  // {
  //   Serial.print(IMU_Angles[i]);
  //   Serial.print("   ");
  // }
  // Serial.println();
}

void Nano_X::Set_Pressure(int Pressure) {
  pressure = Pressure;
  Serial.println(pressure);
}

void Nano_X::Set_Leakage(uint8_t leakValues[8]) {
  for (int i = 0; i < SENSORS_NUM; i++) {
    leakage_values[i] = leakValues[i];
    /*Serial.println();
    Serial.print("Leakage ");
    Serial.print(i);
    Serial.print(" ");
    Serial.print(leakage_values[i]);
    Serial.print(" ");*/
  }
  //Serial.println();
}

void Nano_X::Prepare_frame(uint8_t Dataframe[16]) {
  uint8_t Index = 0;
  for (int i = 0; i < 6; i += 2) {
    Serial.println(i);
    Dataframe[i] = highByte(IMU_Angles[Index]);
    Dataframe[i + 1] = lowByte(IMU_Angles[Index]);
    Index++;
  }

  Dataframe[PRESSURE_index] = pressure >> 8;
  Dataframe[PRESSURE_index + 1] = pressure & 0xFF;

  int j = 0;
  for (int i = 8; i < 16; i++) {
    Dataframe[i] = leakage_values[j];
    j++;
  }

  for(int i= 0;i<8 ; i++)
  {
    Serial.print(Dataframe[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void Nano_X::Send_Data() {
  //Serial.println("Sending...");

  uint8_t Dataframe[16];
  Prepare_frame(Dataframe);
  softSerial.write('(');
  softSerial.write(Dataframe, 16);
  softSerial.write(')');
}

void Nano_X::receive() {
  current = millis();
  uint8_t recFrame[8]= {1,2,3,4};
  while (1/*current - millis() < 50*/) {
    // Serial.println("Inside Receiving...");
    byte x;
    x=readByte();
    if (x != '(') continue;
    for (int i = 0; i < 8; i++) {
      recFrame[i] = readByte();
    }
    x=readByte();
    if (x != ')') continue;
    
    noInterrupts();
   /* Serial.print("Frame is ");
    for (int i = 0; i < 8; i++) {
      Serial.print(recFrame[i]);
      Serial.print(" ");
    }
    Serial.println();*/
    interrupts();
    return;
  }
}

inline byte Nano_X::readByte(){
    //while (!softSerial.available() && current - millis() < 50);
    while (!softSerial.available());
    return softSerial.read();
}

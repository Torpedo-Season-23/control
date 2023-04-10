#include "UartX.h"
#include "config.h"
#include <Arduino.h>
SoftwareSerial softSerial(RX_Y, TX_Y);
//SoftwareSerial sender(TX_Y, RX_Y);

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
}

void Nano_X::Set_Pressure(int Pressure) {
  pressure = Pressure;
}

void Nano_X::Set_Leakage(uint8_t leakValues[8]) {
  for (int i = 0; i < SENSORS_NUM; i++)
    leakage_values[i] = leakValues[i];
}

void Nano_X::Prepare_frame(uint8_t Dataframe[16]) {
  uint8_t Index = 0;
  for (int i = 0; i < 6; i += 2) {
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

  /*for(int i= 0;i<8 ; i++)
  {
    Serial.print(Datafram[i]);
    Serial.print(" ");
  }
  Serial.println();*/
}

void Nano_X::Send_Data() {
  //Serial.println("Sending...");

  uint8_t Dataframe[16];
  Prepare_frame(Dataframe);
  softSerial.write('(');
  // softSerial.write('(');
  softSerial.write(Dataframe, 16);
  // softSerial.write(')');
  softSerial.write(')');
}

void Nano_X::receive() {
  current=millis();
  // Serial.print("Waiting to receive: ");
  //Serial.println(softSerial.available());
  // noInterrupts();
  uint8_t recFrame[8];
  while (current-millis()<50) {
    // Serial.println("Inside Receiving...");
    byte x;
    while (!softSerial.available() && current-millis()<50);
    // Serial.println("hello");
    x = softSerial.read();
    if (x != '(') continue;
    // noInterrupts();
    //Serial.println("before frame");
    for (int i = 0; i < 8; i++) {
      while (!softSerial.available() && current-millis()<50)
        ;

      recFrame[i] = softSerial.read();
      //Serial.println(recFrame[i]);
    }

    while (!softSerial.available() && current-millis()<50)
      ;
    x = softSerial.read();

    // Serial.println("after frame");
    if (x != ')') continue;
    noInterrupts();

    Serial.print("Frame is ");
    for (int i = 0; i < 8; i++) {
      Serial.print(recFrame[i]);
      Serial.print(" ");
    }
    Serial.println();
    interrupts();

    // Serial.println();
    // for (int i = 0; i < 8; i++) { //ACCESSORIES
    //   this->accessories[i] = bitRead(recFrame[0],i); //(recFrame[0] >> (i)) & 0x01
    // }
    return;
  }
}

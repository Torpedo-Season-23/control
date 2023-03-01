#include "UartX.h"
SoftwareSerial softSerial(9, 8);
uint16_t thrusters[6];

void Nano_X::Start_Uart() {
  softSerial.begin(9600);
  IMU_Angles[0] = 0;
  pressure = 0;
  leakage_values[0] = 10;
}
void Nano_X::Set_IMU_Angles(int angles[3]) {
  IMU_Angles[0] = angles[0];
  IMU_Angles[1] = angles[1];
  IMU_Angles[2] = angles[2];
}

void Nano_X::Set_Pressure(int Pressure) {
  pressure = Pressure;
}

void Nano_X::Set_Leakage(uint8_t *leakage_values) {
  for (int i = 0; i < 8; i++) {
    leakage_values[i] = i;
  }
}

void Nano_X::Prepare_frame(uint8_t Datafram[16]) {
  uint8_t Index = 0;
  for (int i = 0; i < 6; i += 2) {
    Datafram[i] = highByte(IMU_Angles[Index]);
    Datafram[i + 1] = lowByte(IMU_Angles[Index]);
    Index++;
  }

  Datafram[PRESSURE_index] = pressure >> 8;
  Datafram[PRESSURE_index + 1] = pressure & 0xFF;

  int j = 0;
  for (int i = 8; i < 16; i++) {
    Datafram[i] = leakage_values[j];
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
  // Serial.println("Sent...");

  uint8_t Datafram[16];
  Prepare_frame(Datafram);
  // softSerial.write('(');
  softSerial.write('(');
  softSerial.write(Datafram, 16);
  softSerial.write(')');
  // softSerial.write(')');
}

void Nano_X::receive() {
  //Serial.print("Waiting to receive: ");
  //Serial.println(softSerial.available());
  uint8_t recFrame[13];
  while (1) {
    byte x;
    while (!softSerial.available())
      ;
    x = softSerial.read();
    if (x != '(') continue;
    for (int i = 0; i < 13; i++) {
      while (!softSerial.available())
        ;
      recFrame[i] = softSerial.read();
    }

    while (!softSerial.available())
      ;
    x = softSerial.read();
    if (x != ')') continue;
    noInterrupts();
    Serial.print("Frame is ");
    for (int i = 0; i < 13; i++) {
      Serial.print(recFrame[i]);
      Serial.print(" ");
    }
    Serial.println();
    int count = 0;
    for (int i = 1; i < 12 + 1; i += 2) {
      thrusters[count] = recFrame[i + 1] * 256 + recFrame[i];
      Serial.print(thrusters[count]);
      Serial.print(" ");
      count++;
    }
    Serial.println();


    interrupts();
    return;
  }
}
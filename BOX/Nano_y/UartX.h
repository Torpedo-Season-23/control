#ifndef UartX_H_
#define Uart_H_
#include <Arduino.h>
#include <SoftwareSerial.h>

class Nano_X {
public:
  uint16_t IMU_Angles[3];
  int pressure;
  uint8_t leakage_values[8];
  //uint16_t thrusters[6];
  //int accessories[8];
  Nano_X();
  void Start_Uart();
  void Set_IMU_Angles(int angles[3]);
  void Set_Pressure(int Pressure);
  void Set_Leakage(uint8_t leakage[8]);
  void Prepare_frame(uint8_t Datafram[8]);
  void Send_Data();
  void receive();
};
#endif
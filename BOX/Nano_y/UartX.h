#ifndef UartX_H_
#define Uart_H_
#include <Arduino.h>
#include <SoftwareSerial.h>

class Nano_X {
public:
  uint16_t IMU_Angles[3];
  int pressure;
  Nano_X();
  void Start_Uart();
  void Set_IMU_Angles(int angles[3]);
  void Set_Pressure(int Pressure);
  void Prepare_frame(uint8_t Datafram[8]);
  void Send_Data();
};
#endif

#include "TorpedoMPU.h"
//#include "Pressure.h"
#include "UartX.h"
TorpedoMPU IMU;
//PressureSensor pressur_S;
Nano_X uart_data;

void handler() {
  Serial.println("In Interrupt!");
  //uint16_t angles[]= {20,30,60};
  //uart_data.Set_IMU_Angles(angles);
  //uart_data.Set_Pressure(25);
  uart_data.Send_Data();
}

void setup() {
  Serial.begin(9600);
  uart_data.Start_Uart();
  // IMU.check();
  //  pressur_S.init();
  attachInterrupt(digitalPinToInterrupt(2), handler, LOW);
}
void loop() {
  //Serial.println("Waiting to receive...");
  uart_data.receive();
  uart_data.Send_Data();
}

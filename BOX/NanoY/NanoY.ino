#include "TorpedoMPU.h"
#include "Pressure.h"
#include "Uart.h"

TorpedoMPU IMU;
PressureSensor pressur_S;
SendData uart_data;

void setup() {
  Serial.begin(9600);
  uart_data.Start_Uart();
  // IMU.check();
  pressur_S.init();
}

void loop() {

uart_data.Set_IMU_Angles(IMU.getangles());
uart_data.Set_Pressure(pressur_S.getPressure());
uart_data.Send_Data();
  
 }
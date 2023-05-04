#include "UartX.h"
#include "Pressure.h"
#include "TorpedoMPU.h"
#include "config.h"

TorpedoMPU IMU;
PressureSensor pressur_S;
Nano_X uart_data;
bool send = false;


long currentTime;

void setup() {
  //currentTime = millis();
  Serial.begin(38400);
  uart_data.Start_Uart();
  IMU.start();
  IMU.check();
  delay(3000);
  pressur_S.init();
}


void loop() {
  long current = millis();
  if (current - currentTime > 0) {
    uart_data.Set_IMU_Angles(IMU.getangles());
    uart_data.Set_Pressure(pressur_S.getPressure());
    currentTime = current;
  }
  Serial.println("Receiving...");
  uart_data.Send_Data();
}

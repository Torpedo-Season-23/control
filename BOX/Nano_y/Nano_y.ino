#include "UartX.h"
#include "Pressure.h"
#include "TorpedoMPU.h"
#include "Leakage.h"
#include "config.h"

TorpedoMPU IMU;
PressureSensor pressur_S;
Nano_X uart_data;
LeakageSensor leakage;
bool send = false;

void handler() {
  Serial.print("Rupt!  ");
  uart_data.Send_Data();
}

long currentTime;

void setup() {
  currentTime = millis();
  Serial.begin(38400);
  uart_data.Start_Uart();
  IMU.start();
  IMU.check();
  delay(3000);
  leakage.init();

  pressur_S.init();
  attachInterrupt(digitalPinToInterrupt(3), handler, LOW);
}


void loop() {
  //return;
  long current = millis();
  if (current - currentTime > 100) {
    uart_data.Set_IMU_Angles(IMU.getangles());
    uart_data.Set_Pressure(pressur_S.getPressure());
    uart_data.Set_Leakage(leakage.getHumidity());
    currentTime = current;
  }
  Serial.println("Receiving...");
  uart_data.receive();
}

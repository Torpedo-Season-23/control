#include "UartX.h"
#include "SensorsOrganizer.h"
//TorpedoMPU IMU;
//PressureSensor pressur_S;
Sensors mySensors;
Nano_X uart_data;

void handler() {
  //Serial.println("In Interrupt!");
  //uart_data.Set_Pressure();

  //uint16_t angles[] = {20, 30, 60};
  //uart_data.Set_IMU_Angles(IMU.getangles());
  uart_data.Send_Data();
}
long currentTime = millis();
void setup() {
  Serial.begin(38400);
  uart_data.Start_Uart();
  //IMU.start();
  mySensors.init();
  //IMU.check();
  //pressur_S.init();
  attachInterrupt(digitalPinToInterrupt(2), handler, LOW);
}
void loop() {
  long current = millis();
  if (current - currentTime > 100) {
    //noInterrupts();
    //Serial.print("HERE!");
    uart_data.Set_IMU_Angles(mySensors.getProxyAngles());
    uart_data.Set_Pressure(mySensors.getProxyPressure());
    currentTime= current;
  }
  //interrupts();
  Serial.println("Waiting to receive...");
  uart_data.receive();
  //uart_data.Send_Data();
}

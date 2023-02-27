#include "UartX.h"
#include "Pressure.h"
#include "TorpedoMPU.h"
#include "Leakage.h"
#include "Multiplexer8.h"

TorpedoMPU IMU;
PressureSensor pressur_S;
Nano_X uart_data;
LeakageSensor leakSensors[8];
int sensors_num = 0;

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
  IMU.start();

  init_mux();
  leakSensors[0].init(); //Q: all wala one? needs to be tested

   for (int i = 0; i < SENSORS_NUM; i++) {
    leakSensors[i].setSensor(i);
  }

  IMU.check();
  pressur_S.init();
  attachInterrupt(digitalPinToInterrupt(2), handler, LOW);
}
void loop() {
  long current = millis();
  if (current - currentTime > 100) {
    //noInterrupts();
    //Serial.print("HERE!");
    uart_data.Set_IMU_Angles(IMU.getangles());
    uart_data.Set_Pressure(pressur_S.getPressure());
    currentTime= current;

    select_mux(sensors_num); //or for loop for all at once? needs to be tested
  uint8_t humidity = leakSensors[sensors_num].getHumidity();

  sensors_num++;

  if(sensors_num > 7)
  {
    sensors_num = 0;
  }
  }
  //interrupts();
  Serial.println("Waiting to receive...");
  uart_data.receive();
  //uart_data.Send_Data();
}

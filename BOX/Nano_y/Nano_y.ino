#include "UartX.h"
#include "Pressure.h"
#include "TorpedoMPU.h"
#include "Leakage.h"
#include "Multiplexer8.h"
#include "config.h"

TorpedoMPU IMU;
PressureSensor pressur_S;
Nano_X uart_data;
LeakageSensor leakSensors[8];
int sensors_num = 0;

void handler() {
  Serial.println("In Interrupt!");
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
  for (int i = 0; i < SENSORS_NUM; i++)  //Q: all wala one? needs to be tested
  {
    leakSensors[i].init();
  }
  for (int i = 0; i < SENSORS_NUM; i++) {
    leakSensors[i].setByte(i);
  }
  IMU.check();
  pressur_S.init();
  attachInterrupt(digitalPinToInterrupt(3), handler, LOW);
}


void loop() {
  long current = millis();
  if (current - currentTime > 100) {
    //noInterrupts();
    //Serial.print("HERE!");
    uart_data.Set_IMU_Angles(IMU.getangles());
    uart_data.Set_Pressure(pressur_S.getPressure());

    currentTime = current;

    // uint8_t arr[8] = 0;
    // for (int i = 0; i < 8; i++) {
    //   arr[i] = leakSensors[i].getHumidity();
    // }

    for (int i = 0; i < 8; i++) {
      select_mux(i); 
      uart_data.Set_Leakage(i, leakSensors[i].getHumidity());
    }
  }
  //interrupts();
  Serial.println("Waiting to receive...");
  uart_data.receive();
  //uart_data.Send_Data();
}
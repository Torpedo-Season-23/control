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
<<<<<<< HEAD
  Serial.println("In Interrupt!");
  uart_data.Send_Data();
=======
  // Serial.println("In Interrupt!");
  // // uart_data.Set_Pressure(uart_data.pressure);
  // //uint16_t angles[] = {20, 30, 60};
  // // uart_data.Set_IMU_Angles(IMU.getangles());
  // uart_data.Send_Data();

  send = true;
  
>>>>>>> tested_system
}

long currentTime;

void setup() {
  currentTime = millis();
  Serial.begin(38400);
  uart_data.Start_Uart();
  IMU.start();
  leakage.init();

  IMU.check();
  pressur_S.init();
  //attachInterrupt(digitalPinToInterrupt(3), handler, CHANGE);
}


void loop() {
  long current = millis();
  if (current - currentTime > 100) {
    Serial.print("HERE!");
    uart_data.Set_IMU_Angles(IMU.getangles());
    uart_data.Set_Pressure(pressur_S.getPressure());
    uart_data.Set_Leakage(0);
<<<<<<< HEAD
    currentTime = current;
  }
  //Serial.println("send");
  uart_data.receive();
=======

    currentTime = current;

    // uint8_t arr[8] = { 0 };
    // uint8_t *leakArr = leakage.getHumidity();
    // for (int i = 0; i < 8; i++) {

    // arr[i] = leakArr[i];
    // }
    // leakage.update();
  }
  // interrupts();
  // Serial.println("Waiting to receive...");
  // uart_data.receive();
  // uart_data.Send_Data();


  ///}
  // interrupts();
  // Serial.println("Waiting to receive...");
  // uart_data.receive();
  // handler();
  // attachInterrupt(digitalPinToInterrupt(3), handler, HIGH);
  // uart_data.Send_Data();
 // if(send){
   uart_data.Send_Data();
   Serial.println("send");
    send = false;
 // }else{

   uart_data.receive();
//  }


>>>>>>> tested_system
}
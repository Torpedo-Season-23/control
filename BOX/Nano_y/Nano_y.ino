#include "UartX.h"
#include "Pressure.h"
#include "TorpedoMPU.h"
#include "Leakage.h"
#include "config.h"

TorpedoMPU IMU;
PressureSensor pressur_S;
Nano_X uart_data;
LeakageSensor leakage;
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
  leakage.init();

  IMU.check();
  pressur_S.init();
 // attachInterrupt(digitalPinToInterrupt(3), handler, LOW);
}


void loop() {
  long current = millis();
  if (current - currentTime > 100) {
    noInterrupts();
    Serial.print("HERE!");
    uart_data.Set_IMU_Angles(IMU.getangles());
    uart_data.Set_Pressure(pressur_S.getPressure());
    

   currentTime = current;

    uint8_t arr[8] = {0};
    uint8_t *leakArr = leakage.getHumidity();
    for (int i = 0; i < 8; i++) {

      arr[i] =leakArr[i] ;
    }
    leakage.update();
<<<<<<< HEAD
    
  }
  interrupts();
  Serial.println("Waiting to receive...");
  uart_data.receive();
  uart_data.Send_Data();
}
=======
  ///}
  //interrupts();
  ///Serial.println("Waiting to receive...");
  ///uart_data.receive();
  //uart_data.Send_Data();
}
>>>>>>> 4f7eed13799d6bb496f2889e5f9930832f45e2d8

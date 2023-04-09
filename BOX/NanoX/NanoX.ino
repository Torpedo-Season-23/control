#include "System.h"
#include "UART_Y.h"
#include "config.h"
#include "Converter.h"

System s;
UART_YZ uart_yz;

Converter convt;

void setup() {
  Serial.begin(115200);
  s.init();
  pinMode(INTERRUPT_PIN, OUTPUT);
  digitalWrite(INTERRUPT_PIN, HIGH);
  uart_yz.begin();
}

void loop() {
  s.receiveData();
  s.activateUART();
  // convt.switchPin();
  s.sendData();
  delay(20);
}

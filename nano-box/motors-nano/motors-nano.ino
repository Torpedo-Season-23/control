#include "lib/code/uart.h"

UART mUart(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);

void setup() {
  Serial.begin(BAUD_RATE);
  mUart.init();
}

void loop() {
  blinkLed();
  mUart.receive();
}

void blinkLed() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

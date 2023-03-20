#include "System.h"
#include "UART_Y.h"
#include "config.h"
System s;
UART_Y uart_y;
 

void setup() {
  Serial.begin(115200);
  s.init();
  pinMode(INTERRUPT_PIN, OUTPUT);
  digitalWrite(INTERRUPT_PIN, LOW);
  uart_y.begin();
}

void loop() {
  s.receiveData();
  s.activateUART();
  s.sendData();
  // Serial.println("hello");


// Serial.println("torpedo");
 

// uart_y.sendFrame(udpReceiveFrame);
// Serial.println("edo");

// digitalWrite(INTERRUPT_PIN, HIGH);
// uart_y.receiveFrame(udpSendFrame);
// digitalWrite(INTERRUPT_PIN, LOW);
  // s.receiveData();
//  // s.activateUART();
//   //Read Here From Converters
  // s.sendData();
}


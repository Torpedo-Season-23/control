#include "System.h"



void System::init() {

  this->client.init();
  uart_yz.begin();
  pinMode(INTERRUPT_PIN, OUTPUT);
  digitalWrite(INTERRUPT_PIN, HIGH);
}

void System::sendData() {
  client.sendData(udpSendFrame);
  Serial.println();
  Serial.print("Sent frame to UDP: ");
  for (int i = 0; i < 16; i++) {
    Serial.print(udpSendFrame[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void System::receiveData() {
  bool i = client.receiveData(udpReceiveFrame);
  if (!i) {
    client.defaultFrame(udpReceiveFrame);
    client.init();
    // Serial.println("Nothing received :(");
    // delay(5);
  } else {
    Serial.print("Received frame from UDP: ");
    for (int i = 0; i < 8; i++) {
      Serial.print(udpReceiveFrame[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
}

void System::activateUART() {
  uart_yz.sendFrame(udpReceiveFrame);

  digitalWrite(INTERRUPT_PIN, LOW);

  uart_yz.receiveFrame(udpSendFrame);

  digitalWrite(INTERRUPT_PIN, HIGH);
}
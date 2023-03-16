#include "System.h"



void System::init() {

  this->client.init();
  uart_y.begin();
  pinMode(INTERRUPT_PIN, OUTPUT);
  digitalWrite(INTERRUPT_PIN, HIGH);
}

void System::sendData()
{
    client.sendData(udpSendFrame);
    delay(10);

}

void System::receiveData()
{
      bool i = client.receiveData(udpReceiveFrame);
  if (!i)
  {
    client.defaultFrame(udpReceiveFrame);
    client.init();
    //Serial.println("Not connected");
   // delay(5);
  }
}

void System::activateUART()
{
  uart_y.sendFrame(udpReceiveFrame);
  // digitalWrite(INTERRUPT_PIN, LOW);
  // uart_y.receiveFrame(udpSendFrame);
  // digitalWrite(INTERRUPT_PIN, HIGH);

}

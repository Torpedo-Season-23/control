#include "System.h"



void System::init() {

  client.init();
  uart_y.begin();
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
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
    Serial.println("Not connected");
    delay(5);
  }
}

void System::activateUART()
{
  client.defaultFrame(udpReceiveFrame);
  uart_y.sendFrame(udpReceiveFrame);
  digitalWrite(PIN, LOW);
  uart_y.receiveFrame(udpSendFrame);
  digitalWrite(PIN, HIGH);

}
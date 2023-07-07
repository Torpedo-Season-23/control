#include "System.h"



void System::init() {
  this->client.init();
  this->client.defaultFrame(udpReceiveFrame);
}

void System::sendData() {
  client.sendData(udpSendFrame);
}

void System::receiveData() {
  bool i = client.receiveData(udpReceiveFrame);
}

void System::activateUART() {
  uart_yz.sendFrame(udpReceiveFrame);
}

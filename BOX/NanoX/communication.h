#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <UIPEthernet.h>
#include <Arduino.h>
#include "config.h"


class CommunicationClient {
private:
  EthernetUDP udp;
  uint8_t mac[6] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };
  IPAddress boxIP;
  IPAddress consoleIP;



public:
  CommunicationClient() {
    this->boxIP = IPAddress(192, 168, 1, 7);
    this->consoleIP = IPAddress(192, 168, 1, 9);
  }

  void init();
  bool receiveData(uint8_t* acc_frame);
  void sendData(uint8_t* frame);
  void defaultFrame(uint8_t* frame);
};


#endif
#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <UIPEthernet.h>
#include <Arduino.h>
#include "Config.h"


class CommunicationClient {
private:
  EthernetUDP udp;
  uint8_t mac[6] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };

public:
  CommunicationClient() {
  }

  void init();
  bool receiveData(uint8_t* acc_frame);
  void sendData(uint8_t* frame);
  void defaultFrame(uint8_t* frame);
};


#endif

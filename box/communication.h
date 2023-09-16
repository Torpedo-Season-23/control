#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <SPI.h>
#include <EthernetENC.h>
#include <Arduino.h>
#include "Config.h"


class CommunicationClient {
private:
  EthernetUDP udp;
  IPAddress ip;
  uint8_t mac[6] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };
public:
  CommunicationClient():ip(192, 168, 1, 7){}
  int toolbyte=0;
  void init();
  bool receiveData(uint8_t* acc_frame);
  void sendData(uint8_t* frame);
  void defaultFrame(uint8_t* frame);
};


#endif

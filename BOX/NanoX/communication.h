#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <UIPEthernet.h>
#include <Arduino.h>
#include "config.h"
#define BOX_PORT 8000
#define CONSOLE_PORT 7000

class CommunicationClient {
private:
  EthernetUDP udp;
  IPAddress consoleIP;
  IPAddress boxIP;
  uint8_t mac[6] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };

  
public:
  CommunicationClient( uint8_t *box,uint8_t *console) {
    this->boxIP = IPAddress(box);;
    this->consoleIP = IPAddress(console);
  }
  
  void Init();
  bool receiveData(uint8_t* acc_frame);
  void sendData(uint8_t* frame);
  int *checkConverter(uint8_t* frame); //will be put in converters file
  int *check_conv[2]; //will be put in converters file
};


#endif

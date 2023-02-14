#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <Arduino.h>
#include <UIPEthernet.h>
#include "config.h"

class Communication {
private:
  EthernetUDP udp;
  IPAddress boxIP;
  IPAddress consoleIP;
  uint16_t boxPort = 8000;
  uint16_t consolePort = 7000;
  uint8_t mac[6] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x06 }; 
public:
  Communication(): consoleIP(192, 168, 1, 9),boxIP(192, 168, 1, 7){}
  void comm_init();
  void receiveData(uint8_t* receivedFrame);
  void getSensors(uint8_t* receivedFrame, int16_t* sensors);
  void prepareData(uint8_t* accessories, double* thrusters, uint8_t* sentFrame);
  void sendData(uint8_t* sentFrame);
};




#endif
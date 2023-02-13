#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <UIPEthernet.h>
#include <Arduino.h>

class CommunicationClient {
private:
  EthernetUDP udp;
  uint16_t BOXPort = 8000;
  IPAddress CONSOLEIP;
  uint16_t CONSOLEPORT = 7000;
  void ips_setting(IPAddress Box, IPAddress Console);
public:
  CommunicationClient( uint8_t *box,uint8_t *console) {
    this->BOXIP = box;
    this->CONSOLEIP = console;
  }
  uint8_t data_sent[10];
  uint8_t* data_received;
  IPAddress BOXIP;
  uint8_t mac[6] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };
  
  void Init();
  void receiveData(uint8_t* acc_frame);
  void sendData(uint8_t* frame);
  //void prep_to_send(int *imu_frame,int imu_size,uint8_t current,int current_size,uint16_t pressure);
};


#endif

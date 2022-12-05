#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <UIPEthernet.h>
union Data{
  uint8_t myByte[4];
  float myfloat;
};

class CommunicationClient {
private:
  EthernetUDP udp;
  Data data;
  uint16_t BOXPort = 8000;
  IPAddress BOXIP;
  IPAddress CONSOLEIP;
  uint16_t CONSOLEPORT = 7000;
  uint8_t mac[6] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };
  int data_size = 0;
  int data_received_size;
  int data_sent_size;
  uint8_t* data_received;
  uint8_t* data_sent;
  void Init();
  void ips_setting(IPAddress Box, IPAddress Console);
public:
  CommunicationClient(const uint8_t pin,int receivesize, int sendsize, IPAddress box, IPAddress console) {
    this->ips_setting(box, console);
    this->Init(pin);
    this->data_received_size = receivesize;
    this->data_sent_size = sendsize;
  }
  void receiveData(uint8_t* acc_frame, uint8_t* thrus_frame);
  void sendData(float *imu_frame,uint8_t imu_size,uint8_t* current,uint8_t current_size,float *pressure,uint8_t pressure_size);
  void prep_to_send(float *imu_frame,uint8_t imu_size,uint8_t* current,uint8_t current_size,float *pressure,uint8_t pressure_size);
};


#endif

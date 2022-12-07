//#include "communication.h"
//
////initiatize the ethertnet module
//void CommunicationClient::Init(uint8_t pin) {
//  Ethernet.init(pin);
//  Ethernet.begin(this->mac, this->BOXIP);
//}
////setting ips of box and console
//void CommunicationClient::ips_setting(IPAddress Box, IPAddress Console) {
//  this->BOXIP = Box;
//  this->CONSOLEIP = Console;
//}
//// receiving function
//void CommunicationClient::receiveData(uint8_t *acc_frame, uint8_t *thrus_frame) {
//  this->udp.begin(this->BOXPort);
//  this->data_size = this->udp.parsePacket();
//  if (this->data_size > 0) {
//    int res = this->udp.read(this->data_received, this->data_size);
//    this->udp.flush();
//    this->udp.stop();
//  }
//  for (int i = 0; i < 8; i++) {
//    if (this->data_received[0] & 1 == 1) acc_frame[i] = 255;
//    else acc_frame[i] = 0;
//    this->data_received[0] >>= 1;
//  }
//  for (int i = 0; i < 8; i++) {
//    if (this->data_received[1] & 1 == 1) thrus_frame[i] = 1;
//    else thrus_frame[i] = 0;
//    this->data_received[1] >>= 1;
//  }
//  int x = 8;
//  for (int i = 2; i < this->data_received_size; i++) {
//    thrus_frame[x] = this->data_received[i];
//    x++;
//  }
//}
////sending function
//void CommunicationClient::sendData(float *imu_frame, int imu_size, uint8_t *current, int current_size, float pressure, int pressure_size) {
//  this->prep_to_send(imu_frame, imu_size, current, current_size, pressure, pressure_size);
//  this->udp.beginPacket(this->CONSOLEIP, this->CONSOLEPORT);
//  this->udp.write(this->data_sent, this->data_sent_size * 2);
//  this->udp.endPacket();
//  this->udp.stop();
//}
//void CommunicationClient::prep_to_send(float *imu_frame, int imu_size, uint8_t *current, int current_size, float pressure, int pressure_size) {
//  this->data_sent_size = imu_size + current_size + pressure_size;
//  int x = 0;
//  for (int i = 0; i < imu_size; i++) {
//    this->data.myfloat = imu_frame[i];
//    for (int j = 0; j < 4; j++) {
//      this->data_sent[x] = this->data.myByte[j];
//      x++;
//    }
//  }
//
//  for (int j = 0; j < current_size ; j++) {
//    this->data_sent[x] = current[j];
//    x++;
//  }
//  for (int i = 0; i < pressure_size; i++) {
//    this->data.myfloat = pressure;
//    for (int j = 0; j < 4; j++) {
//      this->data_sent[x] = this->data.myByte[j];
//      x++;
//    }
//  }
//}

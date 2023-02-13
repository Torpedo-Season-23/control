#include "communication.h"

IPAddress cons(192,168,1,9);
//initiatize the ethertnet module
void CommunicationClient::Init() {
  Ethernet.begin(this->mac, this->BOXIP);
}
//setting ips of box and console
void CommunicationClient::ips_setting(IPAddress Box, IPAddress Console) {

}
// receiving function
void CommunicationClient::receiveData(uint8_t *z_frame) {
  this->udp.begin(this->BOXPort);
  int success;
  success = udp.parsePacket();
  if (success)
  { 
    Serial.print("Received! Success is ");
    Serial.println(success);
    udp.read(z_frame, success + 1);
    /*for(int i= 0;i<3;i++){
      Serial.print(z_frame[i]);
      Serial.print(" ");
    }
    Serial.println();*/
  }
  udp.flush();
}

void CommunicationClient::sendData(uint8_t* frame) {
  udp.beginPacket(cons, 5000);
  int size = udp.write(frame, 15);
  udp.endPacket();
  udp.stop();
}

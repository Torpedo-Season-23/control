#include "communication.h"

IPAddress cons(192,168,1,9);
  uint8_t ff[]={0,1,2,3,4,5,6,7,8,9};
    uint16_t thrusters[6];


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
    int count= 0;
    for(int i= 1;i<13;i++){
      Serial.print(z_frame[i]);
      Serial.print(" ");
    }
    for(int i= 1;i<12+1;i+=2){
      thrusters[count]= z_frame[i+1]*256+z_frame[i];
      Serial.print(thrusters[count]);
      Serial.print(" ");
      count++;
    }
    Serial.println();
  }
  udp.flush();
}

void CommunicationClient::sendData(uint8_t* frame) {
  udp.beginPacket(cons, 7000);
  int size = udp.write(frame, 10);
  udp.endPacket();
  udp.stop();
}

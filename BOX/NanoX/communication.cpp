#include "communication.h"
#include <Arduino.h>

bool setZeros= false;
long currentTime= millis();
void CommunicationClient::init() {
  Ethernet.begin(this->mac, IPAddress(192, 168, 1, 7));
}
void CommunicationClient::defaultFrame(uint8_t* frame) {
  for (int i = 2; i < 8; i++) {
    frame[i] = 0;
  }
}

bool CommunicationClient::receiveData(uint8_t* receivedFrame) {
  /*if(millis()-currentTime>3000){
    setZeros= !setZeros;
    currentTime= millis();
  }
  for(int i= 0;i<UDP_REC_FRAME;i++)
    receivedFrame[i]= setZeros? 255:0;
  return 1;*/
  this->udp.begin(BOX_PORT);
  int success;
  success = udp.parsePacket();
  if (success) {
     //Serial.print("Received! Success is ");
     //Serial.println(success);
    if (success != UDP_REC_FRAME) {
      //Serial.println("Frame incomplete?");
    }
    udp.read(receivedFrame, success);
//    for(int i=2;i<6;i++)
//      receivedFrame
  }
  udp.flush();
  return success > 0;
}

void CommunicationClient::sendData(uint8_t* frame) {
  int x = udp.beginPacket(IPAddress(192, 168, 1, 9), CONSOLE_PORT);
  int size = udp.write(frame, UDP_SEND_FRAME);
  udp.endPacket();
  udp.stop();
}

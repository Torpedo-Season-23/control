#include "communication.h"
#include <Arduino.h>

//initiatize the ethertnet module
void CommunicationClient::init() {

  Ethernet.begin(this->mac, this->boxIP);
}
void CommunicationClient::defaultFrame(uint8_t* frame) {
  for (int i = 2; i < 8; i++)
  {
    // frame[i] = 0x00;
    frame[1] = 89;
    frame[0] = 24+1;
    frame[i] = i+1;
  }
}

bool CommunicationClient::receiveData(uint8_t* receivedFrame) {

  this->udp.begin(BOX_PORT);
  int success;
  success = udp.parsePacket();
  if (success) {
    Serial.print("Received! Success is ");
    Serial.println(success);
    if (success != UDP_REC_FRAME) {
      Serial.println("Frame incomplete?");
    }
    udp.read(receivedFrame, success + 1);
  }
  udp.flush();
  return success > 0;
}

void CommunicationClient::sendData(uint8_t* frame) {

  udp.beginPacket(this->consoleIP, CONSOLE_PORT);
  int size = udp.write(frame, UDP_SEND_FRAME);
  udp.endPacket();
  udp.stop();
}

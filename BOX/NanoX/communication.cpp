#include "communication.h"
#include <Arduino.h>

void CommunicationClient::init() {
  Ethernet.begin(this->mac, IPAddress(192, 168, 1, 7));
}
void CommunicationClient::defaultFrame(uint8_t* frame) {
  for (int i = 2; i < 8; i++) {
    frame[i] = 0;
  }
}

bool CommunicationClient::receiveData(uint8_t* receivedFrame) {

  this->udp.begin(BOX_PORT);
  int success;
  success = udp.parsePacket();
  if (success) {
    if (success != UDP_REC_FRAME) {
      Serial.println("Frame incomplete?");
    }
    udp.read(receivedFrame, success);
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
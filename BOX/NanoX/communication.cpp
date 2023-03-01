#include "communication.h"
#include <Arduino.h>

//initiatize the ethertnet module
void CommunicationClient::Init() {

  Ethernet.begin(this->mac, this->boxIP);
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

int* CommunicationClient::checkConverter(uint8_t* frame) { //will be put in converters file
  for (int i = 6; i < 8; i++) {       
    this->check_conv[i] = bitRead(frame[1],i);  //(frame[1] >> (i)) & 0x01
  }
}
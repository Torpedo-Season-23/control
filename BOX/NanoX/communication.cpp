#include "communication.h"

//initiatize the ethertnet module
void CommunicationClient::Init() {
  Ethernet.begin(this->mac, this->boxIP);
}

// receiving function
bool CommunicationClient::receiveData(uint8_t *receivedFrame) {
  this->udp.begin(BOX_PORT);
  int success;
  success = udp.parsePacket();
  if (success)
  { 
    #ifdef PRINT_ON
      Serial.print("Received! Success is ");
      Serial.println(success);
    #endif
    udp.read(receivedFrame, success + 1);
  }
  udp.flush();
  return success > 0;
}

void CommunicationClient::sendData(uint8_t* frame) {
  udp.beginPacket(this->consoleIP, CONSOLE_PORT);
  int size = udp.write(frame, 13);
  udp.endPacket();
  udp.stop();
}

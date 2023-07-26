#include "communication.h"
#include <Arduino.h>

long lastTimeOnReceive = millis();

void CommunicationClient::init() {
  Ethernet.begin(this->mac, IPAddress(192, 168, 1, 7));
}
void CommunicationClient::defaultFrame(uint8_t* frame) {
  for (int i = 0; i < UDP_REC_FRAME; i++) {
    frame[i] = 0;
  }
}

bool CommunicationClient::receiveData(uint8_t* receivedFrame) {
  this->udp.begin(BOX_PORT);
  int success;
  success = udp.parsePacket();
  if (success) {
    //Debugging
    Serial.print("Received! Success is ");
    Serial.println(success);

    udp.read(receivedFrame, success);
    
    /* debugging
      for(int i= 0;i<8;i++){
       Serial.print(receivedFrame[i]);
       Serial.print(" ");
      }
      Serial.println();*/
    lastTimeOnReceive = millis();
  } else {
    if (millis() - lastTimeOnReceive > 3000) {  //Haven't received for 3 seconds!
      Serial.println("Haven't received for 3 seconds! No UDP Communication");
      for (int i = 2; i < 8; i++)
        receivedFrame[i] = 0;
    }
  }
  udp.flush();
  return success > 0;
}

//for making sure that communication works
void CommunicationClient::sendData(uint8_t* frame) {
  int x = udp.beginPacket(IPAddress(192, 168, 1, 9), CONSOLE_PORT);
  if (!x) {
    this->init();
    return;
  }
  int size = udp.write(frame, UDP_SEND_FRAME);
  udp.endPacket();
  udp.stop();
}

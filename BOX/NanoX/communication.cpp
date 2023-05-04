#include "communication.h"
#include <Arduino.h>

bool setZeros = false;
long lastTimeOnReceive = millis();
void CommunicationClient::init() {
  Ethernet.begin(this->mac, IPAddress(192, 168, 1, 7));
}
void CommunicationClient::defaultFrame(uint8_t* frame) {
  for (int i = 0; i < 8; i++) {
    frame[i] = 0;
  }
}

bool CommunicationClient::receiveData(uint8_t* receivedFrame) {
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
    lastTimeOnReceive = millis();
  }
  else {
    if (millis() - lastTimeOnReceive > 3000) { //Haven't received for 3 seconds!
      Serial.println("No UDP Communication!");
      for (int i = 2; i < 8; i++)
        receivedFrame[i] = 0;
      this->init();
    }
  }
  udp.flush();
  return success > 0;
}

void CommunicationClient::sendData(uint8_t* frame) {

  int x = udp.beginPacket(IPAddress(192, 168, 1, 9), CONSOLE_PORT);
  // for(int i =0 ; i < UDP_SEND_FRAME ; i ++){
  //   frame[i] = 1;
  // }
  Serial.print("Sent frame");
  for (int i = 0 ; i < UDP_SEND_FRAME ; i ++) {
    Serial.print(frame[i] );
    Serial.print(" ");
  }
  Serial.println();

  int size = udp.write(frame, UDP_SEND_FRAME);
  udp.endPacket();
  udp.stop();
}

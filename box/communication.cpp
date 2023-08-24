#include "communication.h"
#include <Arduino.h>

long lastTimeOnReceive = millis();

void CommunicationClient::init() {

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    // while (true) {
    //   delay(1);  // do nothing, no point running without Ethernet hardware
    // }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  Ethernet.begin(this->mac, this->ip);
  Serial.println("Ethernet Connected");

  delay(5000);
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
    Serial.print("Received! Success is ");
    Serial.println(success);
    udp.read(receivedFrame, success);
    lastTimeOnReceive = millis();
  } else {
    if (millis() - lastTimeOnReceive > 3000) {
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
  // if (!x) {
  //   this->init();
  //   return;
  // }
  int size = udp.write(frame, UDP_SEND_FRAME);
  udp.endPacket();
  udp.stop();
}

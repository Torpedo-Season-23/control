#include "communication.h"
#include <Arduino.h>

long lastTimeOnReceive = millis();

void CommunicationClient::init() {

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware :(");
    // while (true) {
    //   delay(1);  // do nothing, no point running without Ethernet hardware
    // }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  Ethernet.begin(this->mac, this->ip);
  Serial.println("Ethernet Connected");
  Serial.print("IP ADDRESS: ");
  Serial.println(this->ip);

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
    for(int i=0 ; i<UDP_SEND_FRAME ; i++)
    {
      Serial.print(receivedFrame[i]);
      Serial.print(" ");
    }
    Serial.println();
      
    lastTimeOnReceive = millis();
  } else {
    if (millis() - lastTimeOnReceive > 3000) {
//      Serial.println("Haven't received for 3 seconds! No UDP Communication");
        receivedFrame[0] = 24;
      for (int i = 1; i < UDP_SEND_FRAME; i++)
        receivedFrame[i] = 0;
       for(int i=0 ; i<UDP_SEND_FRAME ; i++)
    {
      Serial.print(receivedFrame[i]);
      Serial.print(" ");
    }
    Serial.println();
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
//  Serial.println("I'm writing to send data :), ");
//  for(int i=0 ; i<UDP_SEND_FRAME ; i++)
//    frame[i] = i;
  int size = udp.write(frame, UDP_SEND_FRAME);
  udp.endPacket();
  udp.stop();
}

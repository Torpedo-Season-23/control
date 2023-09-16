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
  // frame[0]=0;
  frame[1]=220;
  frame[2]=5;
  frame[3]=220;
  frame[4]=5;
  frame[5]=220;
  frame[6]=5;
  frame[7]=220;
  frame[8]=5;
  frame[9]=220;
  frame[10]=5;
  frame[11]=220;
  frame[12]=5;
 
  // frame[0]=0;
  // for (int i = 1; i < UDP_REC_FRAME; i++) {
  //   if(i%2==0)
  //   frame[i] = 5;
  //   else
  //   frame[i] = 220;

  // }
}

bool CommunicationClient::receiveData(uint8_t* receivedFrame) {
  this->udp.begin(BOX_PORT);
  int success;
  success = udp.parsePacket();
  if (success) {
    udp.read(receivedFrame, 14);
    this->toolbyte=receivedFrame[0];
    //     Serial.print("frame ");
    // // lastTimeOnReceive = millis();
    //  for (int i = 0; i < 13; i++)
    //  {
    //     Serial.print(receivedFrame[i]);
    //     Serial.print(" ");
    //  }
    //  Serial.println();
  } else {
    // if (millis() - lastTimeOnReceive > 3000) {
    //   for (int i = 1; i < 8; i++)
    //     receivedFrame[i] = 0;
    //   // Serial.println("Haven't received for 3 seconds! No UDP Communication");
    // }
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

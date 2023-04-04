#include "communication.h"
#include <math.h>

void Communication::comm_init() {
  Ethernet.begin(this->mac, this->consoleIP);
}

void Communication::receiveData(uint8_t* receivedFrame) {
  this->udp.begin(7000);

  int frameSize = this->udp.parsePacket();
//  Serial.println(frameSize);/
  if (frameSize > 0) {
    this->udp.read(receivedFrame, receivedFrameSize);
    this->udp.flush();
  }
  if (frameSize == 0) {
    // Serial.println("Not received :(");
  } else {
    Serial.print("--------");
    for (int i = 0; i < 10; i++) Serial.print(receivedFrame[i]);
    Serial.println("--------");
//    delay(100);/
  }
 // this->udp.stop();
}

void Communication::getSensors(uint8_t* receivedFrame, int16_t* sensors) {  //modify received frame

  // Serial.println("Readings:");
  int j = 0;
  for (int i = 0; i < IMU + PRESSURE; i++) {
    sensors[i] = receivedFrame[j + 1] + receivedFrame[j] * 256;
    j += 2;
  }
  for (int i = IMU + PRESSURE; i < SENSORS; i++) {
    sensors[i] = receivedFrame[j];
    j++;
    
  }
}

void Communication::prepareData(int* accessories, int* thrusters, uint8_t* sentFrame) {  //modify sent frame
  // 1st byte for accessories
  int x = 0;
  int weights[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
  for (int i = ACCESSORIES - 1; i >= 0; i--) {
    if (accessories[i] == 1) {
      x += weights[i];
    }
  }
  sentFrame[0] = (uint8_t)x;

  // last byte for thrusters' direction
  x = 0;
  //int weights[6] = { 1, 2, 4, 8, 16, 32};
  for (int i = THRUSTERS - 1; i >= 0; i--) {
    if (thrusters[i] > 1500) {
      x += weights[i];  // 1500 will be added in Box
    }
  }
  sentFrame[1] = (uint8_t)x;

  // 6 bytes thrusters' speed
  int j = 0;  // thrusters speed: 1100 - 1900
  for (int i = 2; i < sentFrameSize; i++) {
    thrusters[j] = abs(thrusters[j] - 1500);           //thrusters speed: 0 - 400
    sentFrame[i] = map(thrusters[j], 0, 400, 0, 255);    //thrusters speed: 0 - 255
    j++;
  }

  // int j = 0;
  // for (int i = 1; i < sentFrameSize; i += 2) { //will be changed
  //   sentFrame[i] = lowByte(thrusters[j]);
  //   sentFrame[i + 1] = highByte(thrusters[j]);
  //   j++;
  // }


  // Serial.print("sent frame ");
  // for (int i = 0; i < 13; i++) {
  //   Serial.print(sentFrame[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();
}

void Communication::sendData(uint8_t* sentFrame) {
  int x = this->udp.beginPacket(this->boxIP, this->boxPort);
  if (!x) {
    Serial.println("Problem resolving the hostname or port.");
    this->comm_init();
  }
  /*for(int i=0;i<8;i++){
    Serial.print(" ");
    Serial.print(sentFrame[i]);}
  Serial.println(); */   
  this->udp.write(sentFrame, sentFrameSize);
  this->udp.endPacket();
   this->udp.stop();
}

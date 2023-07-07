#include "communication.h"
#include <math.h>



void Communication::comm_init() {
  Ethernet.begin(this->mac, IPAddress(192, 168, 1, 9));
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
    //Serial.println("Not received :(");
  } else {
    // Serial.print("--------");
    // for (int i = 0; i < receivedFrameSize; i++) 
    // {Serial.print(receivedFrame[i]);
    // Serial.print(" ");}
    // Serial.println("--------");
    int16_t sensors[18];
    this->getSensors(receivedFrame,sensors );
    //delay(100);
  }
  // this->udp.stop();
}

void Communication::getSensors(uint8_t* receivedFrame, int16_t* sensors) {  //modify received frame


  int j = 0;
  // IMU and Pressure readings
  for (int i = 0; i < IMU + PRESSURE; i++) {
    sensors[i] = (int)receivedFrame[j + 1] + receivedFrame[j] * 256;
    j += 2;
  }
  
  // Serial.print("IMU:  ");
  // for(int i=0;i<IMU;i++){
  //   Serial.print(sensors[i]);
  //   Serial.print("  ");
  // }
  // Serial.print("Pressure:  ");
  // for(int i=3;i<PRESSURE;i++){
  //   Serial.print(sensors[i]);
  //   Serial.print("  ");
  // }
  // Serial.print("LEAKAGE:  ");
  // for(int i=4;i<LEAKAGE;i++){
  //   Serial.print(sensors[i]);
  //   Serial.print("  ");
  // }
  // Serial.print("Converter1:  ");
  // for(int i=12;i<3;i++){
  //   Serial.print(sensors[i]);
  //   Serial.print("  ");
  // }  
  // Serial.print("Converter2:  ");
  // for(int i=15;i<3;i++){
  //   Serial.print(sensors[i]);
  //   Serial.print("  ");
  // }
  // Serial.println();


//  Serial.print("Sensors reading: ");
//  for (int i = 0; i < SENSORS; i++) {
//
//    Serial.print(sensors[i]);
//    Serial.print("  ");
//  }
//  Serial.println();
}

void Communication::prepareData(int* accessories, int* thrusters, uint8_t* sentFrame ,bool attach) {  //modify sent frame
  // 1st byte for accessories
  int x = 0;
  int weights[8] = { 1, 2, 4, 8, 16, 32, 64, 128 }; // weights for Accessories
 
  for (int i = ACCESSORIES - 1; i >= 0; i--) {
    if (accessories[i] == 1) {
      x += weights[i];
    }
  }
  sentFrame[0] = (uint8_t)x;

  // 12 bytes thrusters' speed
  int j = 0;  // thrusters speed: 1100 - 1900
  for (int i = 1; i < sentFrameSize; i += 2) {  
    uint16_t thrusterSpeed = (uint16_t) thrusters[j];  
    sentFrame[i] = lowByte(thrusterSpeed);
    sentFrame[i + 1] = highByte(thrusterSpeed);
    j++;
  }

  Serial.print("sent frame ");
  for (int i = 0; i < sentFrameSize; i++) {
    Serial.print(sentFrame[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void Communication::sendData(uint8_t* sentFrame) {
  int x = this->udp.beginPacket(this->boxIP, this->boxPort);
  if (!x) {
    Serial.println("Problem resolving the hostname or port.");
    this->comm_init();
  }
  // for(int i=2;i<8;i++){
  //   Serial.print(" ");
  //   // sentFrame[i]=100;
  //   Serial.print(sentFrame[i]);}
  Serial.println(); 

  this->udp.write(sentFrame, sentFrameSize);
  this->udp.endPacket();
  this->udp.stop();
}

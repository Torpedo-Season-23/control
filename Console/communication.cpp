#include "communication.h"
#include <math.h>

void Communication:: comm_init() {

  Ethernet.begin(this->mac, this->consoleIP);
}

void Communication:: receiveData(uint8_t* receivedFrame) {

  this->udp.begin(this->consolePort);
  
  int frameSize = this->udp.parsePacket();
  Serial.println(frameSize);
  if (frameSize > 0) {
    this->udp.read(receivedFrame, receivedFrameSize);
    this->udp.flush();
    this->udp.stop();
  }
  if (frameSize = 0)
    Serial.print("Not received :(");

}

void Communication:: getSensors(uint8_t* receivedFrame, int16_t* sensors) { 
  
  int j = 0;
  for (int i = 0; i < IMU + PRESSURE; i++) {
    sensors[i] = receivedFrame[j+1] + receivedFrame[j] * 256;
    j += 2;
  }
  for (int i = IMU + PRESSURE; i < SENSORS ; i++) { 
    sensors[i] = receivedFrame[j];
    j++;
  }
  for(int i = SENSORS; i < SENSORS + CURRENT ; i++) 
  {
    sensors[i] = receivedFrame[j+1] + receivedFrame[j] * 256;
    j += 2;
  }
  for(int i = SENSORS + CURRENT ; i < TOTAL ; i++) 
  {
    sensors[i] = receivedFrame[j];
    j++;
  }

}

void Communication:: prepareData(int* accessories, int* thrusters, int* converters, uint8_t* sentFrame) { 

  int x = 0;
  int weights[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

  for (int i = 0 ; i < ACCESSORIES ; i--) {
    if (accessories[i] == 1)
      x += weights[i];
    
  }
  sentFrame[0] = (uint8_t)x;

  x = 0;
  for (int i = 0; i < 6 ; i--) { 
    if (thrusters[i] > 1500)   // 1 FOR +VE , 0 FOR -VE
      x += weights[i];
  }
  for (int i = 6; i < 8 ; i++ )
  {
    if(converters[i-6] == 1)
      x += weights[i];
  }
  sentFrame[1] = (uint8_t)x;


  int j = 0; // thrusters speed: 1100 - 1900
  for(int i = 2; i < sentFrameSize ; i++)
  {
    thrusters[j] = abs(thrusters[j] - 1500);
    sentFrame[i] =  map(thrusters[j] , 0, 400, 0, 255);
    j++;
  }

}

void Communication:: sendData(uint8_t* sentFrame) {
  int x = this->udp.beginPacket(this->boxIP, this->boxPort);
  if (!x) {
    Serial.println("Problem resolving the hostname or port.");
    this->comm_init();
  }
  this->udp.write(sentFrame, sentFrameSize);
  this->udp.endPacket();
  this->udp.stop();
}

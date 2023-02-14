#include "communication.h"

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
}

void Communication:: getSensors(uint8_t* receivedFrame, int16_t* sensors) {  //modify received frame
  Serial.println("Readings:");
  Serial.println("Imu (3 values) -- Pressure (1 value) -- Current (2 values)");  //order of sending needs to be changed in box
  int j = 0;
  for (int i = 0; i < IMU + PRESSURE; i++) {
    sensors[i] = receivedFrame[j] + receivedFrame[j + 1] * 256;
    j += 2;
  }
  for (int i = IMU + PRESSURE; i < SENSORS; i++) {
    sensors[i] = receivedFrame[j];
    j++;
  }
  for (int i = 0; i < SENSORS; i++) {
    Serial.print(sensors[i]);
    Serial.println("  ");
  }
}

void Communication:: prepareData(uint8_t* accessories, double* thrusters, uint8_t* sentFrame) {  //modify sent frame

  int x = 0;
  int weights[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
  for (int i = ACCESSORIES - 1; i >= 0; i--) {
    if (accessories[i] == 255) {
      x += weights[i];
    }
  }
  sentFrame[0] = (uint8_t)x;

  // for (int i = 0; i < ACCESSORIES; i++) {
  //   sentFrame[i] = accessories[i];
  // }

  int j = 0;
  for (int i = ACCESSORIES; i < sentFrameSize; i += 2) {
    sentFrame[i] = lowByte((int16_t)thrusters[j]);
    sentFrame[i + 1] = highByte((int16_t)thrusters[j]);
    j++;
  }
}

void Communication:: sendData(uint8_t* sentFrame) {
  int x = this->udp.beginPacket(this->boxIP, this->boxPort);
  if (!x) {
    Serial.println("Problem resolving the hostname or port");
    this->comm_init();
  }
  this->udp.write(sentFrame, sentFrameSize);
  this->udp.endPacket();
  this->udp.stop();
}

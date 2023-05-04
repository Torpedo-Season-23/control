#include "communication.h"
#include <math.h>


bool conv1 = true;
bool conv2 = true;

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
  // Leakage readings
  for (int i = IMU + PRESSURE; i < IMU + PRESSURE + LEAKAGE; i++) {
    sensors[i] =(int) receivedFrame[j];
    j++;
  }
  // First Converter
  for (int i = IMU + PRESSURE + LEAKAGE; i < IMU + PRESSURE + LEAKAGE + 1; i++) {
    sensors[i] = (int)receivedFrame[j + 1] + receivedFrame[j] * 256;
    j += 2;
  }
//  
  for (int i = IMU + PRESSURE + LEAKAGE + 1; i < IMU + PRESSURE + LEAKAGE + 2; i++) {
    sensors[i] = receivedFrame[j];
    j++;
  }
  sensors[14]=receivedFrame[16];
  j++;
  // Second Converter
  for (int i = IMU + PRESSURE + LEAKAGE + 3; i < IMU + PRESSURE + LEAKAGE + 4; i++) {
    sensors[i] = receivedFrame[j + 1] + receivedFrame[j] * 256;
    j += 2;
  }
<<<<<<< HEAD
  for (int i = IMU + PRESSURE + LEAKAGE + 4; i < SENSORS; i++) {
    sensors[i] = receivedFrame[j];
    j++;
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


  Serial.print("Sensors reading: ");
  for (int i = 0; i < SENSORS; i++) {

=======
  // Leakage readings
  for (int i = IMU + PRESSURE; i < IMU + PRESSURE + LEAKAGE; i++) {
    sensors[i] = receivedFrame[j];
    j++;
  }
  // First Converter
  for (int i = IMU + PRESSURE + LEAKAGE; i < IMU + PRESSURE + LEAKAGE + 1; i++) {
    sensors[i] = receivedFrame[j + 1] + receivedFrame[j] * 256;
    j += 2;
  }
  for (int i = IMU + PRESSURE + LEAKAGE + 1; i < IMU + PRESSURE + LEAKAGE + 2; i++) {
    sensors[i] = receivedFrame[j];
    j++;
  }
  // Second Converter
  for (int i = IMU + PRESSURE + LEAKAGE + 2; i < IMU + PRESSURE + LEAKAGE + 3; i++) {
    sensors[i] = receivedFrame[j + 1] + receivedFrame[j] * 256;
    j += 2;
  }
  for (int i = IMU + PRESSURE + LEAKAGE + 3; i < SENSORS; i++) {
    sensors[i] = receivedFrame[j];
    j++;
  }

  Serial.println("Sensors reading: ");
  for (int i = 0; i < SENSORS; i++) {
>>>>>>> debug_comm
    Serial.print(sensors[i]);
    Serial.print("  ");
  }
  Serial.println();
}

void Communication::prepareData(int* accessories, int* thrusters, uint8_t* sentFrame) {  //modify sent frame
  // 1st byte for accessories
  int x = 0;
  int weights[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
  int th_weights[6] = { 1, 32, 4, 8, 16, 2 };
  for (int i = ACCESSORIES - 1; i >= 0; i--) {
    if (accessories[i] == 1) {
      x += weights[i];
    }
  }
  sentFrame[0] = (uint8_t)x;

  // 2nd byte for thrusters' direction + converters on/off
  x = 0;
  //int weights[6] = { 1, 2, 4, 8, 16, 32};
  for (int i = THRUSTERS - 1; i >= 0; i--) {
    if (thrusters[i] > 1500) {
      x += th_weights[i];  // 1500 will be added in Box
    }
  }
  if (conv1)
    x |= 0b1000000;
  if (conv2)
    x |= 0b10000000;
<<<<<<< HEAD
  // Serial.println(x);
=======
  Serial.println(x);
>>>>>>> debug_comm
  //delay(500);
  sentFrame[1] = (uint8_t)x;

  // 6 bytes thrusters' speed
  int j = 0;  // thrusters speed: 1100 - 1900
<<<<<<< HEAD
  Serial.print("Thrusters:  ");
  for (int i = 2; i < sentFrameSize; i++) {
    Serial.print(thrusters[j]);
    Serial.print("  ");
    
    thrusters[j] = abs(thrusters[j] - 1500);         //thrusters speed: 0 - 400
    sentFrame[i] = map(thrusters[j], 0, 400, 0, 255);;  //thrusters speed: 0 - 255
=======
  for (int i = 2; i < 2 + THRUSTERS ; i++) {
    thrusters[j] = abs(thrusters[j] - 1500);           //thrusters speed: 0 - 400
    sentFrame[i] = map(thrusters[j], 0, 400, 0, 255);  //thrusters speed: 0 - 255
>>>>>>> debug_comm
    j++;
  }
  Serial.println();

  sentFrame[sentFrameSize - 2] = BRAKING_TIME;
  sentFrame[sentFrameSize - 1] = BRAKING_SPEED;
  // int j = 0;
  // for (int i = 1; i < sentFrameSize; i += 2) { //will be changed
  //   sentFrame[i] = lowByte(thrusters[j]);
  //   sentFrame[i + 1] = highByte(thrusters[j]);
  //   j++;
  // }


  // Serial.print("sent frame ");
  // for (int i = 0; i < 8; i++) {
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
<<<<<<< HEAD
  // for(int i=2;i<8;i++){
  //   Serial.print(" ");
  //   // sentFrame[i]=100;
  //   Serial.print(sentFrame[i]);}
  Serial.println(); 
=======
  /*for(int i=0;i<8;i++){
    Serial.print(" ");
    Serial.print(sentFrame[i]);}
  Serial.println(); */
>>>>>>> debug_comm
  this->udp.write(sentFrame, sentFrameSize);
  this->udp.endPacket();
  this->udp.stop();
}

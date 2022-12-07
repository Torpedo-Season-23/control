#include "TorpedoMPU.h"
#include "Pressure.h"
#include "Communication.h"
#include "CurrentSensor.h"
#include"Output_signals.h"
#include "softStart.h"

float thrustersFrame[24] = {0,1,1,1,0,1,1,0, 127 , 100 , 255 , 50 , 100 , 255 , 120, 255 ,33, 20,40,40,20,40,30,40};

float Frame[8] = {0,255,0,255,255,255,255,255};
uint8_t Frame2[4] = {0,255,0,255};
 CommunicationClient Client(53,16,18,IPAddress(198,168,1,7),IPAddress(198,168,1,9));

uint8_t *frame;
uint8_t *thruster;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  // put your setup code here, to run once
 
}

void loop() {
  Serial.println("----------------------");
  Client.receiveData(frame ,thruster );
  Client.sendData(Frame,8,Frame2,4,(float)2.5,1);
//
//  Serial.println(frame[0]);
//  Serial.println(thruster[0]);
  
}

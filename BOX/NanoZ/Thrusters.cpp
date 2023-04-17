#include "Thrusters.h"

bool setZeros= false;
long currentSignalTime= millis();

void Thrusters::init() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].attach(motorPins[i]);
    Motors[i].writeMicroseconds(MOT_ZERO_SPEED);  //stop speed 1500
  }
  delay(1000);
}


//set speeds to Motors
void Thrusters::applySignal() {
  if(millis()-currentSignalTime>3000){
    setZeros= !setZeros;
   currentSignalTime= millis();
  }
  for (int i = 0; i < MOTORS_COUNT; i++) {
    //apply speeds to thrusters
    //Serial.println(thrustersFrame[i]);
    Motors[i].writeMicroseconds(setZeros?1500:1900);
  }
}

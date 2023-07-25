#include "Thrusters.h"

bool setZeros = false;
long currentSignalTime = millis();

void Thruster::initialize(uint8_t pin) {
  this->motor.attach(pin);
  this->currentValue = MOT_ZERO_SPEED;
  this->writeSignal();
}
void Thruster::setSignal(uint16_t value) {
  if (this->currentValue > 1500) {
    if (this->currentValue > value) {
      this->handleBrake(value);
      return;
    } else {
      if (this->currentValue < value) {
        this->handleBrake(value);
        return;
      }
    }
  }
  this->currentValue = value;
  this->writeSignal();
}

void Thruster::handleBrake(uint16_t value) {
  this->currentValue = value;
  this->writeSignal();
  return;
  if (millis() - this->lastUpdatedTime < 100)
    return;
  Serial.println("Braking");

  if (value > this->currentValue) {  //In backwards
    this->currentValue += min(abs(value - this->currentValue), 50);
  } else {
    this->currentValue -= min(abs(value - this->currentValue), 50);
  }
  //Serial.println("New current is ");
  //Serial.println(value);
  this->writeSignal();
  this->lastUpdatedTime = millis();
}
void Thruster::writeSignal() {
  this->motor.writeMicroseconds(this->currentValue);  //stop speed 1500
}

//----------------------------------------------------------//
void Thrusters::init() {
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Motors[i].initialize(motorPins[i]);
  }
  delay(1000);
}


//set speeds to Motors
void Thrusters::applySignal() {
  if (millis() - currentSignalTime > 3000) {
    setZeros = !setZeros;
    currentSignalTime = millis();
  }
  for (int i = 0; i < MOTORS_COUNT; i++) {
    //apply speeds to thrusters
    // Serial.println(thrustersFrame[i]);
    Motors[i].setSignal(thrustersFrame[i]);
  }
  // for(int i=0;i<6;i++){
  // Serial.print(Motors[i].currentValue);
  // Serial.print(" ");
  // }
  // Serial.println();
}

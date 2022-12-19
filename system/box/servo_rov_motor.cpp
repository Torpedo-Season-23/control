#include "servo_rov_motor.h"

ServoROVMotor::ServoROVMotor(unsigned char pin) {
    this->pin = pin;
    this->direction = STOP;
    this->speed = STOP_SPEED;
}

void ServoROVMotor::setSpeed(float speed) {
    speed = speed * this->factor > MAX_INTERVAL ? MAX_INTERVAL : speed;
    if (this->direction == FORWARD) {
        this->speed = STOP_SPEED + speed;
    } else {
        this->speed = STOP_SPEED - speed;
    }
}

void ServoROVMotor::setDirection(DIRECTION direction) {
    this->direction = direction;
}

void ServoROVMotor::setFactor(float factor){
    this->factor = factor;
}
#include "t200_motor.h"

T200Motor::T200Motor(unsigned char pin, float factor) : ServoROVMotor(pin) {
}

void T200Motor::init() {
    pinMode(this->pin, OUTPUT);
}

void T200Motor::reset() {
    this->speed = STOP_SPEED;
}

void T200Motor::forward() {
    this->direction = FORWARD;
    // TODO: Implement this method
}

void T200Motor::backward() {
    this->direction = BACKWARD;
    // TODO: Implement this method
}
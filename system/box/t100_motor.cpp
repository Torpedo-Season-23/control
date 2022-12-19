#include "t100_motor.h"

T100Motor::T100Motor(unsigned char pin, float factor) : ServoROVMotor(pin) {
}

void T100Motor::init() {
    pinMode(this->pin, OUTPUT);
}

void T100Motor::reset() {
    this->speed = STOP_SPEED;
    this->direction = STOP;
}

void T100Motor::forward() {
    this->direction = FORWARD;
    // TODO: Implement this method
}

void T100Motor::backward() {
    this->direction = BACKWARD;
    // TODO: Implement this method
}
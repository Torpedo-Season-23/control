#include "navigation.h"

NAVIGATION::NAVIGATION() {
    this->sensors[PRESSURE] = new PressureSensor();
    this->sensors[IMU] = new IMUSensor();
}

void NAVIGATION::init() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->init();
    }
}

void NAVIGATION::update() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->update();
    }
}

void NAVIGATION::reset() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->reset();
    }
    this->working = false;
}

void NAVIGATION::toggleWorking() {
    this->working = !this->working;
}

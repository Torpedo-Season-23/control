#include "rov.h"

ROV::ROV() {
    this->navigation = new Navigation();
    this->motion = new Motion();
    this->communication = new Ethernet();
}

void ROV::init() {
    this->navigation->init();
    this->motion->init();
    this->communication->init();
}

void ROV::update() {
    this->navigation->update();
    this->communication->update();
}

void ROV::reset() {
    this->navigation->reset();
    this->motion->reset();
    this->communication->reset();
}

void ROV::move(DIRECTION direction) {
    this->direction = direction;
    this->motion->move(direction);
}

void ROV::setSpeed(int speed) {
    this->motion->setSpeed(speed);
}

void ROV::send() {
    this->communication->send();
}

void ROV::recieve() {
    this->communication->recieve();
}
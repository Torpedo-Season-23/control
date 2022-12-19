

ROV::ROV() {
    this->sensorsManager = new SensorsManager();
    this->motion = new Motion();
    this->communication = new EthernetModule();
}

void ROV::init() {
    this->sensorsManager->init();
    this->motion->init();
    this->communication->init();
}

void ROV::update() {
    this->sensorsManager->update();
    this->communication->update();
}

void ROV::reset() {
    this->sensorsManager->reset();
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
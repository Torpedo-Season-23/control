

ROV::ROV() {
    this->direction = STOP;
    this->speed = STOP_SPEED;
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
    // * 1. Recieve data
    this->communication->recieve();

    // * 2. Take data from communication
    uint8_t *frame = this->communication->getFrameRecieved();

    // * 3. Convert communication frame to motor and accessories data
    this->direction = Mapper::getDirection(frame);
    this->speed = Mapper::getSpeed(frame);
    this->accessories = Mapper::getAccessories(frame);

    // * 4. Put direction and speed on motion -> Update motion
    this->motion->update(this->direction, this->speed);

    // TODO: 5. Update accessories

    // * 6. Update sensors
    this->sensorsManager->update();

    // * 7. Take sensors data
    this->communication->setFrameSent(this->sensorsManager->getSensorsData());

    // * 8. Send it to communication
    this->communication->send();
}

void ROV::reset() {
    this->sensorsManager->reset();
    this->motion->reset();
    this->communication->reset();
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
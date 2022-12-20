

ROV::ROV() {
    this->direction = STOP;
    this->speed = STOP_SPEED;
    this->sensorsManager = new SensorsManager();
    this->motion = new Motion();
    this->communication = new EthernetModule();
    this->accessories = new Accessories();
}

void ROV::init() {
    this->motion->init();
    this->accessories->init();
    this->sensorsManager->init();
    this->communication->init();
}

void ROV::work() {
    this->communication->recieve();

    this->data = this->communication->getFrameRecieved();
    this->setMotion(data);
    this->setAccessories(data);
    this->update();

    this->communication->send();
}

void ROV::reset() {
    this->sensorsManager->reset();
    this->motion->reset();
    this->communication->reset();
    this->accessories->reset();
}

void ROV::setMotion(uint8_t frame[FRAME_RECIEVED_SIZE]) {
    this->direction = Mapper::getDirection(frame);
    this->speed = Mapper::getSpeed(frame);
}

void ROV::setAccessories(uint8_t frame[FRAME_RECIEVED_SIZE]) {
    this->accessories->setAccessories(Mapper::getAccessories(frame));
}

void ROV::update() {
    this->motion->update(this->direction, this->speed);
    this->accessories->update();
    this->sensorsManager->update();
    this->communication->setFrameSent(this->sensorsManager->getSensorsData());
}
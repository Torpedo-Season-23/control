

ROV::ROV() {
    this->sensorsManager = new SensorsManager();
    this->motion = new Motion8();
    this->communication = new EthernetModule();
    this->accessories = new Accessories();
}

void ROV::init() {
    this->motion->init();
    this->accessories->init();
    this->sensorsManager->init();
    this->communication->init();
}

void ROV::update() {
    this->communication->recieve();
    this->data = this->communication->getFrameRecieved();
    this->setMotion(data);
    this->setAccessories(data);
    this->setSensors();
    this->communication->send();
}

void ROV::reset() {
    this->sensorsManager->reset();
    this->motion->reset();
    this->communication->reset();
    this->accessories->reset();
}

void ROV::setMotion(uint8_t frame[FRAME_RECIEVED_SIZE]) {
    this->motion->setDirection(Mapper::getDirection(frame));
    this->motion->setSpeed(Mapper::getSpeed(frame));
    this->motion->update();
}

void ROV::setAccessories(uint8_t frame[FRAME_RECIEVED_SIZE]) {
    this->accessories->setAccessories(Mapper::getAccessories(frame));
    this->accessories->update();
    this->sensorsManager->toggleSensorWorking(Mapper::getSensorToToggle(this->accessories->getAccessories()));
}

void ROV::setSensors() {
    this->sensorsManager->update();
    this->communication->setFrameSent(this->sensorsManager->getSensorsData());
}
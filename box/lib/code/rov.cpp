ROV::ROV() {
    this->sensorsManager = new SensorsManager();
    this->motion = new Motion8();
    this->communication = new BoxEthernet();
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
    this->setMotion();
    this->setAccessories();
    this->setSensors();
    this->communication->send();
}

void ROV::reset() {
    this->sensorsManager->reset();
    this->motion->reset();
    this->communication->reset();
    this->accessories->reset();
}

void ROV::setMotion() {
    this->motion->setDirection(Mapper::getDirection(this->data));
    this->motion->setSpeed(Mapper::getSpeed(this->data));
    this->motion->setExponent(Mapper::getExponent(this->data));
    this->motion->update();
}

void ROV::setAccessories() {
    this->accessories->setAccessories(Mapper::getAccessories(this->data));
    this->accessories->update();
    this->sensorsManager->toggleSensorWorking(Mapper::getSensorToToggle(this->accessories->getAccessories()));
}

void ROV::setSensors() {
    this->sensorsManager->update();
    this->communication->setFrameSent(this->sensorsManager->getSensorsData());
}
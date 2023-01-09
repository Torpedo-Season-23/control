ROV::ROV() {
    this->sensorsManager = new SensorsManager();
    this->motion = new Motion8();
    this->communication = new BoxEthernet();
    this->accessories = new Accessories();
    this->mapper = new Mapper();
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
    this->prepareData();
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

void ROV::prepareData() {
    this->mapper->setData(this->data);
}

void ROV::setMotion() {
    this->motion->setDirection(this->mapper->getDirection());
    this->motion->setSpeed(this->mapper->getSpeed());
    this->motion->setExponent(this->mapper->getExponent());
    this->motion->update();
}

void ROV::setAccessories() {
    this->accessories->setAccessories(this->mapper->getAccessories());
    this->accessories->update();
}

void ROV::setSensors() {
    this->sensorsManager->toggleSensorWorking(this->mapper->getSensorToToggle());
    this->sensorsManager->update();
    this->communication->setFrameSent(this->sensorsManager->getSensorsData());
}
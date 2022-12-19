

Navigation::Navigation() {
    this->sensors[PRESSURE] = new PressureSensor();
    this->sensors[IMU] = new IMUSensor();
}

void Navigation::init() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->init();
    }
}

void Navigation::update() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->update();
    }
}

void Navigation::reset() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->reset();
    }
    this->working = false;
}

void Navigation::toggleWorking() {
    this->working = !this->working;
}

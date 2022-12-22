

SensorsManager::SensorsManager() {
    this->sensors[PRESSURE] = new PressureSensor();
    this->sensors[IMU] = new IMUSensor();
    this->sensors[CURRENT_SENSOR_FRONT_LEFT] = new CurrentSensor(CURRENT_SENSOR_FRONT_LEFT_PIN, CURRENT_SENSOR_FRONT_LEFT);
    this->sensors[CURRENT_SENSOR_FRONT_RIGHT] = new CurrentSensor(CURRENT_SENSOR_FRONT_RIGHT_PIN, CURRENT_SENSOR_FRONT_RIGHT);
    this->sensors[CURRENT_SENSOR_BACK_LEFT] = new CurrentSensor(CURRENT_SENSOR_BACK_LEFT_PIN, CURRENT_SENSOR_BACK_LEFT);
    this->sensors[CURRENT_SENSOR_BACK_RIGHT] = new CurrentSensor(CURRENT_SENSOR_BACK_RIGHT_PIN, CURRENT_SENSOR_BACK_RIGHT);
    for (int i = 0; i < SENSORS_DATA_SIZE; i++) {
        this->sensorsData[i] = 0;
    }
}

void SensorsManager::init() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->init();
    }
    this->working = true;
}

void SensorsManager::update() {
    if (!this->working) return;
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->update();
    }
}

void SensorsManager::reset() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->reset();
    }
}

void SensorsManager::startWorking() {
    this->working = true;
}

void SensorsManager::stopWorking() {
    this->working = false;
}

void SensorsManager::toggleWorking() {
    this->working = !this->working;
}

void SensorsManager::toggleSensorWorking(SENSOR_TYPE sensor) {
    switch (sensor) {
        case IMU:
            this->sensors[IMU]->toggleWorking();
            break;
        case PRESSURE:
            this->sensors[PRESSURE]->toggleWorking();
            break;
        default:
            break;
    }
}

void SensorsManager::prepareSensorsData() {
    // TODO: implement
}

uint8_t* SensorsManager::getSensorsData() {
    this->prepareSensorsData();
    return this->sensorsData;
}
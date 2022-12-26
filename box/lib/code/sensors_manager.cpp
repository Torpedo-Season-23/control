SensorsManager::SensorsManager() {
    this->sensors[SENSOR_TYPE::PRESSURE] = new PressureSensor();
    this->sensors[SENSOR_TYPE::IMU] = new MPU6050Sensor();
    this->sensors[SENSOR_TYPE::CURRENT_SENSOR_FRONT_LEFT] = new CurrentSensor(CURRENT_SENSOR_FRONT_LEFT_PIN, SENSOR_TYPE::CURRENT_SENSOR_FRONT_LEFT);
    this->sensors[SENSOR_TYPE::CURRENT_SENSOR_FRONT_RIGHT] = new CurrentSensor(CURRENT_SENSOR_FRONT_RIGHT_PIN, SENSOR_TYPE::CURRENT_SENSOR_FRONT_RIGHT);
    this->sensors[SENSOR_TYPE::CURRENT_SENSOR_BACK_LEFT] = new CurrentSensor(CURRENT_SENSOR_BACK_LEFT_PIN, SENSOR_TYPE::CURRENT_SENSOR_BACK_LEFT);
    this->sensors[SENSOR_TYPE::CURRENT_SENSOR_BACK_RIGHT] = new CurrentSensor(CURRENT_SENSOR_BACK_RIGHT_PIN, SENSOR_TYPE::CURRENT_SENSOR_BACK_RIGHT);
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
        this->sensorsData[i] = this->sensors[i]->getData();
    }
    if (DEBUG_SENSORS)
        this->display();
}

uint8_t* SensorsManager::getSensorsData() {
    return (uint8_t*)this->sensorsData;
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
        case SENSOR_TYPE::IMU:
            this->sensors[SENSOR_TYPE::IMU]->toggleWorking();
            break;
        case SENSOR_TYPE::PRESSURE:
            this->sensors[SENSOR_TYPE::PRESSURE]->toggleWorking();
            break;
        default:
            break;
    }
}

void SensorsManager::display() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->display();
        Serial.println();
    }
    Serial.println();
}
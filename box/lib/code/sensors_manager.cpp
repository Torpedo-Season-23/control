

SensorsManager::SensorsManager() {
    this->sensors[PRESSURE] = new PressureSensor();
    this->sensors[IMU] = new IMUSensor();
    this->currentSensors[CURRENT_SENSOR_FRONT_LEFT] = new CurrentSensor(CURRENT_SENSOR_FRONT_LEFT_PIN, CURRENT_SENSOR_FRONT_LEFT);
    this->currentSensors[CURRENT_SENSOR_FRONT_RIGHT] = new CurrentSensor(CURRENT_SENSOR_FRONT_RIGHT_PIN, CURRENT_SENSOR_FRONT_RIGHT);
    this->currentSensors[CURRENT_SENSOR_BACK_LEFT] = new CurrentSensor(CURRENT_SENSOR_BACK_LEFT_PIN, CURRENT_SENSOR_BACK_LEFT);
    this->currentSensors[CURRENT_SENSOR_BACK_RIGHT] = new CurrentSensor(CURRENT_SENSOR_BACK_RIGHT_PIN, CURRENT_SENSOR_BACK_RIGHT);
    for (int i = 0; i < SENSORS_DATA_SIZE; i++) {
        this->sensorsData[i] = 0;
    }
}

void SensorsManager::init() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->init();
    }
    for (int i = 0; i < CURRENT_SENSOR_COUNT; i++) {
        currentSensors[i]->init();
    }
}

void SensorsManager::update() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->update();
    }
    for (int i = 0; i < CURRENT_SENSOR_COUNT; i++) {
        currentSensors[i]->update();
    }
}

void SensorsManager::reset() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i]->reset();
    }
    for (int i = 0; i < CURRENT_SENSOR_COUNT; i++) {
        currentSensors[i]->reset();
    }
    this->working = false;
}

void SensorsManager::toggleWorking() {
    this->working = !this->working;
}

void SensorsManager::prepareSensorsData() {
    // TODO: implement
}

uint8_t* SensorsManager::getSensorsData() {
    this->prepareSensorsData();
    return this->sensorsData;
}
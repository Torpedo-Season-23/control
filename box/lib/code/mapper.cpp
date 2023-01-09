void Mapper::setData(uint8_t communicationFrame[FRAME_RECIEVED_SIZE]) {
    for (uint8_t i = 0; i < FRAME_RECIEVED_SIZE; i++) {
        this->data[i] = communicationFrame[i];
    }
    this->setDirection();
    this->setSpeed();
    this->setExponent();
    this->setAccessories();
    this->setSensorToToggle();
}

void Mapper::setDirection() {
    this->direction = static_cast<DIRECTION>(this->data[DIRECTION_INDEX]);
}
void Mapper::setSpeed() {
    uint8_t i = 0, j = SPEED_INDEX_START;
    while (i < MOTOR_COUNT) {
        this->speed[i++] = this->data[j++] + (this->data[j++] * 256);
    }
}

void Mapper::setExponent() {
    uint8_t exponent[MOTOR_COUNT];
    uint8_t i = 0, j = EXPONENT_INDEX_START;
    while (i < EXPONENT_COUNT) {
        this->exponent[i++] = this->data[j++] + (this->data[j++] * 256);
    }
}

void Mapper::setAccessories() {
    this->accessories = this->data[ACCESSORIES_INDEX];
}
void Mapper::setSensorToToggle() {
    this->sensorToToggle = this->accessories << IMU_TOGGLE == 1 ? IMU : this->accessories << PRESSURE_TOGGLE == 1 ? PRESSURE
                                                                                                                  : NO_SENSOR;
}

DIRECTION Mapper::getDirection() {
    return this->direction;
}

uint16_t* Mapper::getSpeed() {
    return this->speed;
}

uint8_t* Mapper::getExponent() {
    return this->exponent;
}

uint8_t Mapper::getAccessories() {
    return this->accessories;
}

SENSOR_TYPE Mapper::getSensorToToggle() {
    return this->sensorToToggle;
}
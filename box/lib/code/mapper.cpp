static DIRECTION Mapper::getDirection(uint8_t communicationFrame[FRAME_RECIEVED_SIZE]) {
    return static_cast<DIRECTION>(communicationFrame[DIRECTION_INDEX]);
}
static uint8_t* Mapper::getSpeed(uint8_t communicationFrame[FRAME_RECIEVED_SIZE]) {
    uint8_t speed[MOTOR_COUNT];
    uint8_t i = 0, j = SPEED_INDEX_START;
    while (i < MOTOR_COUNT) {
        speed[i++] = communicationFrame[j++] + communicationFrame[j++];
    }
    return speed;
}

static uint8_t* Mapper::getExponent(uint8_t communicationFrame[FRAME_RECIEVED_SIZE]) {
    uint8_t exponent[MOTOR_COUNT];
    uint8_t i = 0, j = EXPONENT_INDEX_START;
    while (i < MOTOR_COUNT) {
        exponent[i++] = communicationFrame[j++] + communicationFrame[j++];
    }
    return exponent;
}

static uint8_t Mapper::getAccessories(uint8_t communicationFrame[FRAME_RECIEVED_SIZE]) {
    return communicationFrame[ACCESSORIES_INDEX];
}

static SENSOR_TYPE Mapper::getSensorToToggle(uint8_t accessoriesFrame) {
    return accessoriesFrame << IMU_TOGGLE == 1 ? IMU : accessoriesFrame << PRESSURE_TOGGLE == 1 ? PRESSURE
                                                                                                : NO_SENSOR;
}
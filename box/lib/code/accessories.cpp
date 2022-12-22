Accessories::Accessories() {
    this->data = 0;
    this->pins[RIGHT_GRIPPER] = RIGHT_GRIPPER_PIN;
    this->pins[LEFT_GRIPPER] = LEFT_GRIPPER_PIN;
    this->pins[LIGHTS] = LIGHTS_PIN;
    this->pins[IMU_TOGGLE] = IMU_TOGGLE_PIN;
    this->pins[PRESSURE_TOGGLE] = PRESSURE_TOGGLE_PIN;
    this->pins[ACCESORIES_EMPTY1] = ACCESORIES_EMPTY1_PIN;
    this->pins[ACCESORIES_EMPTY2] = ACCESORIES_EMPTY2_PIN;
    this->pins[ACCESORIES_EMPTY3] = ACCESORIES_EMPTY3_PIN;
}

void Accessories::init() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        pinMode(this->pins[i], OUTPUT);
    }
}

void Accessories::update() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        // TODO: Check
        digitalWrite(this->pins[i], this->data << i == 1 ? HIGH : LOW);
    }
}

void Accessories::reset() {
    this->data = 0;
    this->init();
}

void Accessories::setAccessories(uint8_t frame) {
    this->data = frame;
}

uint8_t Accessories::getAccessories() {
    return this->data;
}
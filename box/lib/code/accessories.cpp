Accessories::Accessories() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        this->data[i] = 0;
    }
    this->pins[RIGHT_GRIPPER] = RIGHT_GRIPPER_PIN;
    this->pins[LEFT_GRIPPER] = LEFT_GRIPPER_PIN;
    this->pins[LIGHTS] = LIGHTS_PIN;
    this->pins[ACCESORIES_EMPTY1] = ACCESORIES_EMPTY1_PIN;
    this->pins[ACCESORIES_EMPTY2] = ACCESORIES_EMPTY2_PIN;
    this->pins[ACCESORIES_EMPTY3] = ACCESORIES_EMPTY3_PIN;
    this->pins[ACCESORIES_EMPTY4] = ACCESORIES_EMPTY4_PIN;
    this->pins[ACCESORIES_EMPTY5] = ACCESORIES_EMPTY5_PIN;
}

void Accessories::init() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        pinMode(this->pins[i], OUTPUT);
    }
}

void Accessories::update() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        digitalWrite(pins[i], data[i]);
    }
}

void Accessories::reset() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        this->data[i] = 0;
    }
}

void Accessories::setAccessories(uint8_t frame[ACCESSORIES_COUNT]) {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        this->data[i] = frame[i];
    }
}
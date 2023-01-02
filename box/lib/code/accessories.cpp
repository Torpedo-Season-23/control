Accessories::Accessories() {
    this->data = 0;
    this->pins[ACCESSORIES_TYPE::RIGHT_GRIPPER] = RIGHT_GRIPPER_PIN;
    this->pins[ACCESSORIES_TYPE::LEFT_GRIPPER] = LEFT_GRIPPER_PIN;
    this->pins[ACCESSORIES_TYPE::LIGHTS] = LIGHTS_PIN;
    this->pins[ACCESSORIES_TYPE::IMU_TOGGLE] = IMU_TOGGLE_PIN;
    this->pins[ACCESSORIES_TYPE::PRESSURE_TOGGLE] = PRESSURE_TOGGLE_PIN;
    this->pins[ACCESSORIES_TYPE::ACCESORIES_EMPTY1] = ACCESORIES_EMPTY1_PIN;
    this->pins[ACCESSORIES_TYPE::ACCESORIES_EMPTY2] = ACCESORIES_EMPTY2_PIN;
    this->pins[ACCESSORIES_TYPE::ACCESORIES_EMPTY3] = ACCESORIES_EMPTY3_PIN;
}

void Accessories::init() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        pinMode(this->pins[i], OUTPUT);
    }
}

void Accessories::update() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        digitalWrite(this->pins[i], (this->data >> i) & 1 == 1 ? HIGH : LOW);
    }
    if (DEBUG_ACCESSORIES)
        this->display();
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

void Accessories::display() {
    for (uint8_t i = 0; i < ACCESSORIES_COUNT; i++) {
        Serial.print(Helper::getAccessoriesType((ACCESSORIES_TYPE)i));
        Serial.print(": ");
        Serial.print(Helper::getOnOff(this->data << i));
        if (i < ACCESSORIES_COUNT - 1)
            Serial.print(" | ");
    }
    Serial.println();
}
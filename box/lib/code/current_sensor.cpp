
CurrentSensor::CurrentSensor(unsigned char pin, CURRENT_SENSOR_TYPE type) {
    this->pin = pin;
    this->type = type;
    this->current = 0;
}

void CurrentSensor::init() {
    pinMode(this->pin, INPUT);
}

void CurrentSensor::update() {
    float value = 0, samples = 0, avg = 0;
    for (int i = 0; i < 150; i++) {
        value = analogRead(this->pin);
        samples = samples + value;
        delay(3);
    }
    avg = samples / 150.0;
    this->current = (2.5 - (avg * (5.0 / 1024.0))) / 0.185;

    if (DEBUG)
        this->display();
}

float CurrentSensor::getCurrent() {
    return current;
}

void CurrentSensor::reset() {
    this->current = 0;
}

char const* getType(CURRENT_SENSOR_TYPE type) {
    switch (type) {
        case CURRENT_SENSOR_BACK_LEFT:
            return "Back Left";
        case CURRENT_SENSOR_BACK_RIGHT:
            return "Back Right";
        case CURRENT_SENSOR_FRONT_LEFT:
            return "Front Left";
        case CURRENT_SENSOR_FRONT_RIGHT:
            return "Front Right";
        default:
            return "Unknown";
    }
}

void CurrentSensor::display() {
    Serial.print("Sensor: ");
    Serial.print(getType(this->type));
    Serial.print(" | Current: ");
    Serial.print(this->current);
    Serial.println(" A");
}
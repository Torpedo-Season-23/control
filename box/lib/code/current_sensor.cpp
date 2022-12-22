CurrentSensor::CurrentSensor(unsigned char pin, SENSOR_TYPE type) {
    this->pin = pin;
    this->type = type;
    this->current = 0;
}

void CurrentSensor::init() {
    this->working = true;
    pinMode(this->pin, INPUT);
}

void CurrentSensor::update() {
    if (!this->working) return;
    float value = 0, samples = 0, avg = 0;
    for (int i = 0; i < 150; i++) {
        value = analogRead(this->pin);
        samples = samples + value;
        delay(3);
    }
    avg = samples / 150.0;
    this->current = (2.5 - (avg * (5.0 / 1024.0))) / 0.185;
    this->data = this->current;

    if (DEBUG_SENSORS)
        this->display();
}

float CurrentSensor::getCurrent() {
    return current;
}

void CurrentSensor::reset() {
    this->current = 0;
}

void CurrentSensor::display() {
    Serial.print("Sensor: ");
    Serial.print(Helper::getCurrentSensorType(this->type));
    Serial.print(" | Current: ");
    Serial.print(this->current);
    Serial.println(" A");
}
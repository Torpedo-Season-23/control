
ServoROVMotor::ServoROVMotor(unsigned char pin) {
    this->pin = pin;
    this->direction = STOP;
    this->speed = STOP_SPEED;
}

void ServoROVMotor::setSpeed(float speed, float factor = 1) {
    speed = speed * factor > MAX_INTERVAL ? MAX_INTERVAL : speed;
    if (this->direction == FORWARD) {
        this->speed = STOP_SPEED + speed;
    } else {
        this->speed = STOP_SPEED - speed;
    }
}

void ServoROVMotor::setDirection(DIRECTION direction) {
    this->direction = direction;
}

void ServoROVMotor::clockWise() {
    this->direction = FORWARD;
    // TODO: implement
}

void ServoROVMotor::antiClockWise() {
    this->direction = BACKWARD;
    // TODO: implement
}

void ServoROVMotor::stop() {
    this->direction = STOP;
    this->speed = STOP_SPEED;
    // TODO: implement
}

void ServoROVMotor::init() {
    pinMode(this->pin, OUTPUT);
    // TODO: implement
}

void ServoROVMotor::reset() {
    this->direction = STOP;
    this->speed = STOP_SPEED;
}

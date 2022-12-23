ServoROVMotor::ServoROVMotor(unsigned char pin, MOTOR_ORIENTATION type) {
    this->pin = pin;
    this->direction = STOP;
    this->type = type;
    this->speed = STOP_SPEED;
    this->servo = new Servo();
}

void ServoROVMotor::init() {
    this->servo->attach(this->pin);
    this->servo->writeMicroseconds(STOP_SPEED);
    Soft::softStartInitial();
}

void ServoROVMotor::setSpeed(uint8_t speed) {
    speed = speed > MAX_INTERVAL ? MAX_INTERVAL : speed;
    if (this->direction == FORWARD)
        this->speed = STOP_SPEED + speed;
    else if (this->direction == BACKWARD)
        this->speed = STOP_SPEED - speed;
    else if (this->direction == GENERIC)
        this->speed = speed;
    else
        this->speed = STOP;
}

void ServoROVMotor::reset() {
    this->stop();
}

void ServoROVMotor::clockWise(uint8_t speed) {
    this->direction = FORWARD;
    uint8_t previousSpeed = this->speed;
    this->setSpeed(speed);
    Soft::motorSoftStart(this->servo, previousSpeed, &this->speed, this->type, this->exponent);
}

void ServoROVMotor::antiClockWise(uint8_t speed) {
    this->direction = BACKWARD;
    uint8_t previousSpeed = this->speed;
    this->setSpeed(speed);
    Soft::motorSoftStart(this->servo, previousSpeed, &this->speed, this->type, this->exponent);
}

void ServoROVMotor::stop() {
    this->direction = STOP;
    this->speed = STOP_SPEED;
    servo->writeMicroseconds(this->speed);
}

void ServoROVMotor::putSpeed(uint8_t speed) {
    this->speed = GENERIC;
    uint8_t previousSpeed = this->speed;
    this->setSpeed(speed);
    Soft::motorSoftStart(this->servo, previousSpeed, &this->speed, this->type, this->exponent);
}

void ServoROVMotor::setExponent(float exponent) {
    this->exponent = exponent;
}

MOTOR_ORIENTATION ServoROVMotor::getType() {
    return this->type;
}

uint8_t ServoROVMotor::getSpeed() {
    return this->speed;
}
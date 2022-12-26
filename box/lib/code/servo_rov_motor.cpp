ServoROVMotor::ServoROVMotor(unsigned char pin, MOTOR_ORIENTATION type) {
    this->pin = pin;
    this->direction = DIRECTION::STOP;
    this->type = type;
    this->speed = STOP_SPEED;
    this->exponent = EXPONENT_INITAL;
    this->servo = new Servo();
}

void ServoROVMotor::init() {
    this->servo->attach(this->pin);
    this->servo->writeMicroseconds(STOP_SPEED);
    Soft::softStartInitial();
}

void ServoROVMotor::setSpeed(uint16_t speed) {
    speed = speed > MAX_INTERVAL ? MAX_INTERVAL : speed;
    if (this->direction == FORWARD)
        this->speed = STOP_SPEED + speed;
    else if (this->direction == BACKWARD)
        this->speed = STOP_SPEED - speed;
    else if (this->direction == GENERIC)
        this->speed = speed;
    else
        this->speed = STOP_SPEED;
}

void ServoROVMotor::reset() {
    this->stop();
}

void ServoROVMotor::clockWise(uint16_t speed) {
    this->direction = DIRECTION::FORWARD;
    uint16_t previousSpeed = this->speed;
    this->setSpeed(speed);
    Soft::motorSoftStart(this->servo, previousSpeed, &this->speed, this->type, this->exponent);
}

void ServoROVMotor::antiClockWise(uint16_t speed) {
    this->direction = DIRECTION::BACKWARD;
    uint16_t previousSpeed = this->speed;
    this->setSpeed(speed);
    Soft::motorSoftStart(this->servo, previousSpeed, &this->speed, this->type, this->exponent);
}

void ServoROVMotor::stop() {
    this->direction = DIRECTION::STOP;
    this->speed = STOP_SPEED;
    servo->writeMicroseconds(this->speed);
}

void ServoROVMotor::putSpeed(uint16_t speed) {
    this->speed = DIRECTION::GENERIC;
    uint16_t previousSpeed = this->speed;
    this->setSpeed(speed);
    Soft::motorSoftStart(this->servo, previousSpeed, &this->speed, this->type, this->exponent);
}

void ServoROVMotor::setExponent(float exponent) {
    this->exponent = exponent;
}

MOTOR_ORIENTATION ServoROVMotor::getType() {
    return this->type;
}

uint16_t ServoROVMotor::getSpeed() {
    return this->speed;
}

void ServoROVMotor::display() {
    Serial.print("Motor: ");
    Serial.print(Helper::getMotorType(this->type));
    Serial.print(" | Direction: ");
    Serial.print(Helper::getDirection(this->direction));
    Serial.print(" | Speed: ");
    Serial.print(this->speed);
}

void ServoROVMotor::update() {
    if (this->direction == STOP)
        this->stop();
    else if (this->direction == GENERIC)
        this->putSpeed(STOP_SPEED + 100);
    else if (this->direction == FORWARD)
        this->clockWise(STOP_SPEED + 100);
    else if (this->direction == BACKWARD)
        this->antiClockWise(STOP_SPEED + 100);
}
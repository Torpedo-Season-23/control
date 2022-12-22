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
}

void ServoROVMotor::setSpeed(uint8_t speed) {
    speed = speed > MAX_INTERVAL ? MAX_INTERVAL : speed;
    if (this->direction == FORWARD)
        this->speed = STOP_SPEED + speed;
    else if (this->direction == BACKWARD)
        this->speed = STOP_SPEED - speed;
    else
        this->speed = STOP_SPEED;
}

void ServoROVMotor::reset() {
    this->stop();
}

void ServoROVMotor::clockWise(uint8_t speed) {
    this->direction = FORWARD;
    this->setSpeed(speed);
    servo->writeMicroseconds(this->speed);
}

void ServoROVMotor::antiClockWise(uint8_t speed) {
    this->direction = BACKWARD;
    this->setSpeed(this->speed);
    servo->writeMicroseconds(this->speed);
}

void ServoROVMotor::stop() {
    this->direction = STOP;
    this->speed = STOP_SPEED;
    servo->writeMicroseconds(this->speed);
}

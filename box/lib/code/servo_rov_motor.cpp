
ServoROVMotor::ServoROVMotor(unsigned char pin, MOTOR_ORIENTATION type) {
    this->pin = pin;
    this->direction = STOP;
    this->type = type;
    this->speed = STOP_SPEED;
    this->servo = new Servo();
}

void ServoROVMotor::setSpeed(float speed) {
    if (speed == STOP_SPEED) {
        this->stop();
        return;
    }
    speed = speed > MAX_INTERVAL ? MAX_INTERVAL : speed;
    if (this->direction == FORWARD)
        this->speed = STOP_SPEED + speed;
    else
        this->speed = STOP_SPEED - speed;
}

void ServoROVMotor::clockWise(float speed) {
    this->direction = FORWARD;
    this->setSpeed(speed);
    // TODO: implement
}

void ServoROVMotor::antiClockWise(float speed) {
    this->direction = BACKWARD;
    this->setSpeed(this->speed);
    // TODO: implement
}

void ServoROVMotor::stop() {
    this->direction = STOP;
    this->speed = STOP_SPEED;
    // TODO: implement
}

void ServoROVMotor::init() {
    this->servo->attach(this->pin);
    this->servo->writeMicroseconds(STOP_SPEED);
}
ServoROVMotor::ServoROVMotor(unsigned char pin, MOTOR_ORIENTATION type) {
  this->pin = pin;
  this->direction = DIRECTION::STOP;
  this->type = type;
  this->speed = STOP_SPEED;
  this->exponent = EXPONENT_INITAL;
  this->servo = new Servo();
  this->softStart = false;
}

void ServoROVMotor::init() {
  this->servo->attach(this->pin);
  this->servo->writeMicroseconds(STOP_SPEED);
  if (this->softStart) Soft::softStartInitial();
}

void ServoROVMotor::setSpeed(uint16_t speed) {
  this->speed = min(speed, MAX_SPEED);
}

void ServoROVMotor::reset() {
  this->stop();
}

void ServoROVMotor::clockWise(uint16_t speed) {
  this->direction = DIRECTION::FORWARD;
  uint16_t previousSpeed = this->speed;
  this->setSpeed(speed);
  this->apply(previousSpeed);
}

void ServoROVMotor::antiClockWise(uint16_t speed) {
  this->direction = DIRECTION::BACKWARD;
  uint16_t previousSpeed = this->speed;
  this->setSpeed(speed);
  this->apply(previousSpeed);
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
  this->apply(previousSpeed);
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

void ServoROVMotor::apply(uint16_t previousSpeed) {
  if (this->softStart)
    Soft::motorSoftStart(this->servo, previousSpeed, &this->speed, this->type, this->exponent);
  else
    this->servo->writeMicroseconds(this->speed);
}
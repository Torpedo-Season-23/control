MotorsMapper::MotorsMapper() {
}

void MotorsMapper::setData(uint8_t frame[MOTORS_FRAME_SIZE]) {
  for (uint8_t i = 0; i < MOTORS_FRAME_SIZE; i++) {
    this->data[i] = frame[i];
  }
  this->setDirection();
  this->setSpeed();
  this->setExponent();
}

void MotorsMapper::setSpeed() {
  uint8_t i = 0, j = SPEED_INDEX_START;
  while (i < MOTOR_COUNT)
    this->speed[i++] = this->data[j++] + (this->data[j++] * 256);
}

void MotorsMapper::setDirection() {
  this->direction = static_cast<DIRECTION>(this->data[DIRECTION_INDEX]);
}

void MotorsMapper::setExponent() {
  uint8_t i = 0, j = EXPONENT_INDEX_START;
  while (i < EXPONENT_COUNT) {
    this->exponent[i++] = this->data[j++] + (this->data[j++] * 256);
  }
}

DIRECTION MotorsMapper::getDirection() {
  return this->direction;
}

uint16_t* MotorsMapper::getSpeed() {
  return this->speed;
}

uint8_t* MotorsMapper::getExponent() {
  return this->exponent;
}
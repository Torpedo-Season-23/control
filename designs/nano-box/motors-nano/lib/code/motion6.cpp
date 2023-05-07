Motion6::Motion6() {
  this->direction = DIRECTION::STOP;
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT] = new T200Motor(HORIZONTAL_FRONT_LEFT_PIN, MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT] = new T200Motor(HORIZONTAL_FRONT_RIGHT_PIN, MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT] = new T200Motor(HORIZONTAL_BACK_LEFT_PIN, MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT] = new T200Motor(HORIZONTAL_BACK_RIGHT_PIN, MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT);
  this->motors[MOTOR_ORIENTATION::VERTICAL_FRONT] = new T200Motor(VERTICAL_FRONT_PIN, MOTOR_ORIENTATION::VERTICAL_FRONT);
  this->motors[MOTOR_ORIENTATION::VERTICAL_BACK] = new T200Motor(VERTICAL_BACK_PIN, MOTOR_ORIENTATION::VERTICAL_BACK);
}

void Motion6::init() {
  for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
    motors[i]->init();
  }
}

void Motion6::update() {
  this->move();
}

void Motion6::move() {
  switch (this->direction) {
    case DIRECTION::FORWARD:
      this->forward();
      break;
    case DIRECTION::BACKWARD:
      this->backward();
      break;
    case DIRECTION::LEFT:
      this->left();
      break;
    case DIRECTION::RIGHT:
      this->right();
      break;
    case DIRECTION::MOMENT_LEFT:
      this->momentLeft();
      break;
    case DIRECTION::MOMENT_RIGHT:
      this->momentRight();
      break;
    case DIRECTION::UP:
      this->up();
      break;
    case DIRECTION::DOWN:
      this->down();
      break;
    case DIRECTION::STOP:
      this->stop();
      break;
    case DIRECTION::GENERIC:
      this->generic();
      break;
    default:
      break;
  }
}

void Motion6::forward() {
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion6::backward() {
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion6::left() {
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion6::right() {
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion6::momentLeft() {
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion6::momentRight() {
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
  this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion6::up() {
  this->motors[MOTOR_ORIENTATION::VERTICAL_FRONT]->clockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_FRONT]);
  this->motors[MOTOR_ORIENTATION::VERTICAL_BACK]->clockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_BACK]);
}

void Motion6::down() {
  this->motors[MOTOR_ORIENTATION::VERTICAL_FRONT]->antiClockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_FRONT]);
  this->motors[MOTOR_ORIENTATION::VERTICAL_BACK]->antiClockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_BACK]);
}

void Motion6::generic() {
  for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
    this->motors[i]->putSpeed(this->speed[i]);
  }
}

void Motion6::stop() {
  this->direction = STOP;
  for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
    motors[i]->stop();
  }
}

void Motion6::reset() {
  this->direction = STOP;
  for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
    motors[i]->reset();
  }
  this->init();
}

void Motion6::setSpeed(uint16_t *speed) {
  for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
    this->speed[i] = speed[i];
  }
}

void Motion6::setExponent(uint8_t *exponent) {
  for (uint8_t i = 0; i < EXPONENT_COUNT; i++) {
    this->motors[i]->setExponent(exponent[i]);
  }
}

void Motion6::setDirection(DIRECTION direction) {
  this->direction = direction;
}
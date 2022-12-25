Motion8::Motion8() {
    this->direction = STOP;
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT] = new T200Motor(HORIZONTAL_FRONT_LEFT_PIN, MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT] = new T200Motor(HORIZONTAL_FRONT_RIGHT_PIN, MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT] = new T200Motor(HORIZONTAL_BACK_LEFT_PIN, MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT] = new T200Motor(HORIZONTAL_BACK_RIGHT_PIN, MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT);
    this->motors[MOTOR_ORIENTATION::VERTICAL_FRONT] = new T200Motor(VERTICAL_FRONT_PIN, MOTOR_ORIENTATION::VERTICAL_FRONT);
    this->motors[MOTOR_ORIENTATION::VERTICAL_BACK] = new T200Motor(VERTICAL_BACK_PIN, MOTOR_ORIENTATION::VERTICAL_BACK);
    this->motors[MOTOR_ORIENTATION::VERTICAL_LEFT] = new T100Motor(VERTICAL_LEFT_PIN, MOTOR_ORIENTATION::VERTICAL_LEFT);
    this->motors[MOTOR_ORIENTATION::VERTICAL_RIGHT] = new T100Motor(VERTICAL_RIGHT_PIN, MOTOR_ORIENTATION::VERTICAL_RIGHT);
}

void Motion8::init() {
    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->init();
    }
}

void Motion8::update() {
    this->move();
    if (DEBUG_MOTION)
        this->display();
}

void Motion8::move() {
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

void Motion8::forward() {
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion8::backward() {
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion8::left() {
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion8::right() {
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion8::momentLeft() {
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion8::momentRight() {
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT]);
    this->motors[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT]);
}

void Motion8::up() {
    this->motors[MOTOR_ORIENTATION::VERTICAL_FRONT]->clockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_FRONT]);
    this->motors[MOTOR_ORIENTATION::VERTICAL_BACK]->clockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_BACK]);
    this->motors[MOTOR_ORIENTATION::VERTICAL_LEFT]->clockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_LEFT]);
    this->motors[MOTOR_ORIENTATION::VERTICAL_RIGHT]->clockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_RIGHT]);
}

void Motion8::down() {
    this->motors[MOTOR_ORIENTATION::VERTICAL_FRONT]->antiClockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_FRONT]);
    this->motors[MOTOR_ORIENTATION::VERTICAL_BACK]->antiClockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_BACK]);
    this->motors[MOTOR_ORIENTATION::VERTICAL_LEFT]->antiClockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_LEFT]);
    this->motors[MOTOR_ORIENTATION::VERTICAL_RIGHT]->antiClockWise(this->speed[MOTOR_ORIENTATION::VERTICAL_RIGHT]);
}

void Motion8::generic() {
    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        this->motors[i]->putSpeed(this->speed[i]);
    }
}

void Motion8::stop() {
    this->direction = STOP;
    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->stop();
    }
}

void Motion8::reset() {
    this->direction = STOP;
    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->reset();
    }
    this->init();
}

void Motion8::display() {
    Serial.print("Motion8: ");
    Serial.print("Direction: ");
    Serial.print(Helper::getDirection(this->direction));
    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        this->motors[i]->display();
        if (i < MOTOR_COUNT - 1) {
            Serial.print(" | ");
        }
    }
    Serial.println();
}

void Motion8::setSpeed(uint8_t *speed) {
    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        this->speed[i] = speed[i];
    }
}

void Motion8::setExponent(uint8_t *exponent) {
    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        this->motors[i]->setExponent(exponent[i]);
    }
}

void Motion8::setDirection(DIRECTION direction) {
    this->direction = direction;
}
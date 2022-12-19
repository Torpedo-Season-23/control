

Motion::Motion() {
    this->direction = STOP;
    this->motors[HOTIZONTAL_FRONT_LEFT] = new T200Motor(HORIZONTAL_FRONT_LEFT_PIN);
    this->motors[HOTIZONTAL_FRONT_RIGHT] = new T200Motor(HORIZONTAL_FRONT_RIGHT_PIN);
    this->motors[HOTIZONTAL_BACK_LEFT] = new T200Motor(HORIZONTAL_BACK_LEFT_PIN);
    this->motors[HOTIZONTAL_BACK_RIGHT] = new T200Motor(HORIZONTAL_BACK_RIGHT_PIN);
    this->motors[VERTICAL_FRONT] = new T200Motor(VERTICAL_FRONT_PIN);
    this->motors[VERTICAL_BACK] = new T200Motor(VERTICAL_BACK_PIN);
    this->motors[VERTICAL_LEFT] = new T100Motor(VERTICAL_LEFT_PIN);
    this->motors[VERTICAL_RIGHT] = new T100Motor(VERTICAL_RIGHT_PIN);
}

void Motion::init() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->init();
    }
}

void Motion::move(DIRECTION direction) {
    switch (direction) {
        case FORWARD:
            this->forward();
            break;
        case BACKWARD:
            this->backward();
            break;
        case LEFT:
            this->left();
            break;
        case RIGHT:
            this->right();
            break;
        case MOMENT_LEFT:
            this->momentLeft();
            break;
        case MOMENT_RIGHT:
            this->momentRight();
            break;
        case UP:
            this->up();
            break;
        case DOWN:
            this->down();
            break;
        default:
            break;
    }
}

void Motion::forward() {
    this->direction = FORWARD;
    this->motors[HOTIZONTAL_FRONT_LEFT]->clockWise();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->clockWise();
    this->motors[HOTIZONTAL_BACK_LEFT]->clockWise();
    this->motors[HOTIZONTAL_BACK_RIGHT]->clockWise();
}

void Motion::backward() {
    this->direction = BACKWARD;
    this->motors[HOTIZONTAL_FRONT_LEFT]->antiClockWise();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->antiClockWise();
    this->motors[HOTIZONTAL_BACK_LEFT]->antiClockWise();
    this->motors[HOTIZONTAL_BACK_RIGHT]->antiClockWise();
}

void Motion::left() {
    this->direction = LEFT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->antiClockWise();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->clockWise();
    this->motors[HOTIZONTAL_BACK_LEFT]->antiClockWise();
    this->motors[HOTIZONTAL_BACK_RIGHT]->clockWise();
}

void Motion::right() {
    this->direction = RIGHT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->clockWise();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->antiClockWise();
    this->motors[HOTIZONTAL_BACK_LEFT]->clockWise();
    this->motors[HOTIZONTAL_BACK_RIGHT]->antiClockWise();
}

void Motion::momentLeft() {
    this->direction = MOMENT_LEFT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->antiClockWise();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->clockWise();
    this->motors[HOTIZONTAL_BACK_LEFT]->clockWise();
    this->motors[HOTIZONTAL_BACK_RIGHT]->antiClockWise();
}

void Motion::momentRight() {
    this->direction = MOMENT_RIGHT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->clockWise();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->antiClockWise();
    this->motors[HOTIZONTAL_BACK_LEFT]->antiClockWise();
    this->motors[HOTIZONTAL_BACK_RIGHT]->clockWise();
}

void Motion::up() {
    this->direction = UP;
    this->motors[VERTICAL_FRONT]->clockWise();
    this->motors[VERTICAL_BACK]->clockWise();
    this->motors[VERTICAL_LEFT]->clockWise();
    this->motors[VERTICAL_RIGHT]->clockWise();
}

void Motion::down() {
    this->direction = DOWN;
    this->motors[VERTICAL_FRONT]->antiClockWise();
    this->motors[VERTICAL_BACK]->antiClockWise();
    this->motors[VERTICAL_LEFT]->antiClockWise();
    this->motors[VERTICAL_RIGHT]->antiClockWise();
}

void Motion::setSpeed(int speed) {
    if (this->direction != STOP) {
        for (int i = 0; i < MOTOR_COUNT; i++) {
            motors[i]->setSpeed(speed);
        }
    } else {
        for (int i = 0; i < MOTOR_COUNT; i++) {
            motors[i]->setSpeed(STOP_SPEED);
        }
    }
}

void Motion::reset() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->reset();
    }
}

void Motion::stop() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->stop();
    }
}

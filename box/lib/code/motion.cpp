

Motion::Motion() {
    this->direction = STOP;
    this->motors[HOTIZONTAL_FRONT_LEFT] = new T200Motor(HORIZONTAL_FRONT_LEFT_PIN, HOTIZONTAL_FRONT_LEFT);
    this->motors[HOTIZONTAL_FRONT_RIGHT] = new T200Motor(HORIZONTAL_FRONT_RIGHT_PIN, HOTIZONTAL_FRONT_RIGHT);
    this->motors[HOTIZONTAL_BACK_LEFT] = new T200Motor(HORIZONTAL_BACK_LEFT_PIN, HOTIZONTAL_BACK_LEFT);
    this->motors[HOTIZONTAL_BACK_RIGHT] = new T200Motor(HORIZONTAL_BACK_RIGHT_PIN, HOTIZONTAL_BACK_RIGHT);
    this->motors[VERTICAL_FRONT] = new T200Motor(VERTICAL_FRONT_PIN, VERTICAL_FRONT);
    this->motors[VERTICAL_BACK] = new T200Motor(VERTICAL_BACK_PIN, VERTICAL_BACK);
    this->motors[VERTICAL_LEFT] = new T100Motor(VERTICAL_LEFT_PIN, VERTICAL_LEFT);
    this->motors[VERTICAL_RIGHT] = new T100Motor(VERTICAL_RIGHT_PIN, VERTICAL_RIGHT);
}

void Motion::init() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->init();
    }
}

void Motion::update(DIRECTION direction, float speed) {
    this->direction = direction;
    this->speed = speed;
    this->move();
}

void Motion::move() {
    switch (this->direction) {
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
    this->motors[HOTIZONTAL_FRONT_LEFT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_FRONT_RIGHT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_LEFT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_RIGHT]->clockWise(this->speed);
}

void Motion::backward() {
    this->direction = BACKWARD;
    this->motors[HOTIZONTAL_FRONT_LEFT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_LEFT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_RIGHT]->antiClockWise(this->speed);
}

void Motion::left() {
    this->direction = LEFT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_FRONT_RIGHT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_LEFT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_RIGHT]->clockWise(this->speed);
}

void Motion::right() {
    this->direction = RIGHT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_LEFT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_RIGHT]->antiClockWise(this->speed);
}

void Motion::momentLeft() {
    this->direction = MOMENT_LEFT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_FRONT_RIGHT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_LEFT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_RIGHT]->antiClockWise(this->speed);
}

void Motion::momentRight() {
    this->direction = MOMENT_RIGHT;
    this->motors[HOTIZONTAL_FRONT_LEFT]->clockWise(this->speed);
    this->motors[HOTIZONTAL_FRONT_RIGHT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_LEFT]->antiClockWise(this->speed);
    this->motors[HOTIZONTAL_BACK_RIGHT]->clockWise(this->speed);
}

void Motion::up() {
    this->direction = UP;
    this->motors[VERTICAL_FRONT]->clockWise(this->speed);
    this->motors[VERTICAL_BACK]->clockWise(this->speed);
    this->motors[VERTICAL_LEFT]->clockWise(this->speed);
    this->motors[VERTICAL_RIGHT]->clockWise(this->speed);
}

void Motion::down() {
    this->direction = DOWN;
    this->motors[VERTICAL_FRONT]->antiClockWise(this->speed);
    this->motors[VERTICAL_BACK]->antiClockWise(this->speed);
    this->motors[VERTICAL_LEFT]->antiClockWise(this->speed);
    this->motors[VERTICAL_RIGHT]->antiClockWise(this->speed);
}

void Motion::reset() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->stop();
    }
}

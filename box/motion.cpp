#include "motion.h"

Motion::Motion() {
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
    this->motors[HOTIZONTAL_FRONT_LEFT]->forward();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->forward();
    this->motors[HOTIZONTAL_BACK_LEFT]->forward();
    this->motors[HOTIZONTAL_BACK_RIGHT]->forward();
}

void Motion::backward() {
    this->motors[HOTIZONTAL_FRONT_LEFT]->backward();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->backward();
    this->motors[HOTIZONTAL_BACK_LEFT]->backward();
    this->motors[HOTIZONTAL_BACK_RIGHT]->backward();
}

void Motion::left() {
    this->motors[HOTIZONTAL_FRONT_LEFT]->backward();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->forward();
    this->motors[HOTIZONTAL_BACK_LEFT]->backward();
    this->motors[HOTIZONTAL_BACK_RIGHT]->forward();
}

void Motion::right() {
    this->motors[HOTIZONTAL_FRONT_LEFT]->forward();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->backward();
    this->motors[HOTIZONTAL_BACK_LEFT]->forward();
    this->motors[HOTIZONTAL_BACK_RIGHT]->backward();
}

void Motion::momentLeft() {
    this->motors[HOTIZONTAL_FRONT_LEFT]->backward();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->forward();
    this->motors[HOTIZONTAL_BACK_LEFT]->forward();
    this->motors[HOTIZONTAL_BACK_RIGHT]->backward();
}

void Motion::momentRight() {
    this->motors[HOTIZONTAL_FRONT_LEFT]->forward();
    this->motors[HOTIZONTAL_FRONT_RIGHT]->backward();
    this->motors[HOTIZONTAL_BACK_LEFT]->backward();
    this->motors[HOTIZONTAL_BACK_RIGHT]->forward();
}

void Motion::up() {
    this->motors[VERTICAL_FRONT]->forward();
    this->motors[VERTICAL_BACK]->forward();
    this->motors[VERTICAL_LEFT]->forward();
    this->motors[VERTICAL_RIGHT]->forward();
}

void Motion::down() {
    this->motors[VERTICAL_FRONT]->backward();
    this->motors[VERTICAL_BACK]->backward();
    this->motors[VERTICAL_LEFT]->backward();
    this->motors[VERTICAL_RIGHT]->backward();
}

void Motion::setSpeed(int speed) {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->setSpeed(speed);
    }
}

void Motion::reset() {
    for (int i = 0; i < MOTOR_COUNT; i++) {
        motors[i]->reset();
    }
}

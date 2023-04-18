float exponent = 2.0;

int dir = SOFT_START_UP;
long int time1[8], time2[8], speed_counter[8] = {0};

static void Soft::softStartInitial() {
    for (char i = 0; i < 8; i++) {
        time1[i] = millis();
        time2[i] = millis();
    }
}
static void Soft::softStart(char type, uint16_t motor_speed, uint16_t *motor_controlled_speed, MOTOR_ORIENTATION i) {
    if ((time2[i] - time1[i]) >= TIME_STEP) {
        time1[i] = millis();
        speed_counter[i]++;

        switch (type) {
            case SOFT_START_UP:
                *motor_controlled_speed = SOFT_START_UP;
                break;
            case SOFT_START_DOWN:
                *motor_controlled_speed = SOFT_START_DOWN;
                break;
        }

        if (abs(motor_speed - *motor_controlled_speed) <= STEP_SPEED) {
            *motor_controlled_speed = motor_speed;
            speed_counter[i] = 0;
        }
    }
    time2[i] = millis();
}

static void Soft::motorSoftStart(Servo *motor_num, uint16_t motor_speed, uint16_t *motor_controlled_speed, MOTOR_ORIENTATION i, float EXP) {
    exponent = EXP;

    if (motor_speed < 1100 || motor_speed > 1900)
        motor_speed = 1500;
    if (motor_speed == MOT_ZERO_SPEED) {
        *motor_controlled_speed = MOT_ZERO_SPEED;
        speed_counter[i] = 0;
    }

    else if ((motor_speed > MOT_ZERO_SPEED) && (*motor_controlled_speed < MOT_ZERO_SPEED)) {
        *motor_controlled_speed = MOT_ZERO_SPEED;
        speed_counter[i] = 0;
    }

    else if ((motor_speed > MOT_ZERO_SPEED) && (motor_speed < *motor_controlled_speed)) {
        *motor_controlled_speed = motor_speed;
        speed_counter[i] = TIME_STEP_RETURN_UP;
    }

    else if ((motor_speed < MOT_ZERO_SPEED) && (*motor_controlled_speed > MOT_ZERO_SPEED)) {
        *motor_controlled_speed = MOT_ZERO_SPEED;
        speed_counter[i] = 0;
    }

    else if ((motor_speed < MOT_ZERO_SPEED) && (motor_speed > *motor_controlled_speed)) {
        *motor_controlled_speed = motor_speed;
        speed_counter[i] = TIME_STEP_RETURN_DOWN;

    }

    else if ((motor_speed > MOT_ZERO_SPEED) && (*motor_controlled_speed >= MOT_ZERO_SPEED) && (*motor_controlled_speed < motor_speed)) {
        if (speed_counter[i] == 0) {
            speed_counter[i] = TIME_STEP_RETURN_UP;
        }

        softStart(SOFT_START_UP, motor_speed, motor_controlled_speed, i);
        dir = SOFT_START_UP;
    }

    else if ((motor_speed < MOT_ZERO_SPEED) && (*motor_controlled_speed <= MOT_ZERO_SPEED) && (*motor_controlled_speed > motor_speed)) {
        if (speed_counter[i] == 0) {
            speed_counter[i] = TIME_STEP_RETURN_DOWN;
        }

        softStart(SOFT_START_DOWN, motor_speed, motor_controlled_speed, i);
        dir = SOFT_START_DOWN;
    }

    motor_num->writeMicroseconds(*motor_controlled_speed);
}
static char const* Helper::getDirection(DIRECTION direction) {
    switch (direction) {
        case DIRECTION::FORWARD:
            return "Forward";
        case DIRECTION::BACKWARD:
            return "Backward";
        case DIRECTION::LEFT:
            return "Left";
        case DIRECTION::RIGHT:
            return "Right";
        case DIRECTION::MOMENT_LEFT:
            return "Moment Left";
        case DIRECTION::MOMENT_RIGHT:
            return "Moment Right";
        case DIRECTION::UP:
            return "Up";
        case DIRECTION::DOWN:
            return "Down";
        case DIRECTION::STOP:
            return "Stop";
        case DIRECTION::GENERIC:
            return "Generic";
        default:
            return "Unknown";
    }
}

static char const* Helper::getMotorType(MOTOR_ORIENTATION type) {
    switch (type) {
        case MOTOR_ORIENTATION::HORIZONTAL_FRONT_LEFT:
            return "Horizontal Front Left";
        case MOTOR_ORIENTATION::HORIZONTAL_FRONT_RIGHT:
            return "Horizontal Front Right";
        case MOTOR_ORIENTATION::HORIZONTAL_BACK_LEFT:
            return "Horizontal Back Left";
        case MOTOR_ORIENTATION::HORIZONTAL_BACK_RIGHT:
            return "Horizontal Back Right";
        case MOTOR_ORIENTATION::VERTICAL_BACK:
            return "Vertical Back";
        case MOTOR_ORIENTATION::VERTICAL_FRONT:
            return "Vertical Front";
        case MOTOR_ORIENTATION::VERTICAL_LEFT:
            return "Vertical Left";
        case MOTOR_ORIENTATION::VERTICAL_RIGHT:
            return "Vertical Right";
        default:
            return "Unknown";
    }
}

static char const* Helper::getSensorType(SENSOR_TYPE type) {
    switch (type) {
        case SENSOR_TYPE::IMU:
            return "IMU";
        case SENSOR_TYPE::PRESSURE:
            return "Pressure";
        default:
            return "Unknown";
    }
}

static char const* Helper::getAccessoriesType(ACCESSORIES_TYPE type) {
    switch (type) {
        case ACCESSORIES_TYPE::LEFT_GRIPPER:
            return "Left Gripper";
        case ACCESSORIES_TYPE::RIGHT_GRIPPER:
            return "Right Gripper";
        case ACCESSORIES_TYPE::LIGHTS:
            return "Lights";
        case ACCESSORIES_TYPE::IMU_TOGGLE:
            return "IMU Toggle";
        case ACCESSORIES_TYPE::PRESSURE_TOGGLE:
            return "Pressure Toggle";
        case ACCESSORIES_TYPE::ACCESORIES_EMPTY1:
            return "Accesories Empty1";
        case ACCESSORIES_TYPE::ACCESORIES_EMPTY2:
            return "Accesories Empty2";
        case ACCESSORIES_TYPE::ACCESORIES_EMPTY3:
            return "Accesories Empty3";
        default:
            return "Unknown";
    }
}

static char const* Helper::getOnOff(uint8_t value) {
    return value == 0 ? "OFF" : "ON";
}
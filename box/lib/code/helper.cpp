static char const* Helper::getDirection(DIRECTION direction) {
    switch (direction) {
        case FORWARD:
            return "Forward";
        case BACKWARD:
            return "Backward";
        case LEFT:
            return "Left";
        case RIGHT:
            return "Right";
        case MOMENT_LEFT:
            return "Moment Left";
        case MOMENT_RIGHT:
            return "Moment Right";
        case UP:
            return "Up";
        case DOWN:
            return "Down";
        case STOP:
            return "Stop";
        default:
            return "Unknown";
    }
}

static char const* Helper::getMotorType(MOTOR_ORIENTATION type) {
    switch (type) {
        case HORIZONTAL_FRONT_LEFT:
            return "Horizontal Front Left";
        case HORIZONTAL_FRONT_RIGHT:
            return "Horizontal Front Right";
        case HORIZONTAL_BACK_LEFT:
            return "Horizontal Back Left";
        case HORIZONTAL_BACK_RIGHT:
            return "Horizontal Back Right";
        case VERTICAL_BACK:
            return "Vertical Back";
        case VERTICAL_FRONT:
            return "Vertical Front";
        case VERTICAL_LEFT:
            return "Vertical Left";
        case VERTICAL_RIGHT:
            return "Vertical Right";
        default:
            return "Unknown";
    }
}

static char const* Helper::getSensorType(SENSOR_TYPE type) {
    switch (type) {
        case IMU:
            return "IMU";
        case CURRENT_SENSOR_BACK_LEFT:
            return "Current Sensor Back Left";
        case CURRENT_SENSOR_BACK_RIGHT:
            return "Current Sensor Back Right";
        case CURRENT_SENSOR_FRONT_LEFT:
            return "Current Sensor Front Left";
        case CURRENT_SENSOR_FRONT_RIGHT:
            return "Current Sensor Front Right";
        case PRESSURE:
            return "Pressure";
        default:
            return "Unknown";
    }
}

static char const* Helper::getAccessoriesType(ACCESSORIES_TYPE type) {
    switch (type) {
        case LEFT_GRIPPER:
            return "Left Gripper";
        case RIGHT_GRIPPER:
            return "Right Gripper";
        case LIGHTS:
            return "Lights";
        case IMU_TOGGLE:
            return "IMU Toggle";
        case PRESSURE_TOGGLE:
            return "Pressure Toggle";
        case ACCESORIES_EMPTY1:
            return "Accesories Empty1";
        case ACCESORIES_EMPTY2:
            return "Accesories Empty2";
        case ACCESORIES_EMPTY3:
            return "Accesories Empty3";
        default:
            return "Unknown";
    }
}

static char const* Helper::getOnOff(uint8_t value) {
    return value == 0 ? "OFF" : "ON";
}
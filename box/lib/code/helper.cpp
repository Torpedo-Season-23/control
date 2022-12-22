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

static char const* Helper::getCurrentSensorType(SENSOR_TYPE type) {
    switch (type) {
        case CURRENT_SENSOR_BACK_LEFT:
            return "Back Left";
        case CURRENT_SENSOR_BACK_RIGHT:
            return "Back Right";
        case CURRENT_SENSOR_FRONT_LEFT:
            return "Front Left";
        case CURRENT_SENSOR_FRONT_RIGHT:
            return "Front Right";
        default:
            return "Unknown";
    }
}
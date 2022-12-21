

IMUSensor::IMUSensor() {
    this->scl = IMU_SCL;
    this->sda = IMU_SDA;
    this->accel_x = 0;
    this->accel_y = 0;
    this->accel_z = 0;
    this->gyro_x = 0;
    this->gyro_y = 0;
    this->gyro_z = 0;
    this->mag_x = 0;
    this->mag_y = 0;
    this->mag_z = 0;
    this->temp = 0;
}

void IMUSensor::init() {
    // TODO: implement
}

void IMUSensor::update() {
    // TODO: implement

    if (DEBUG_SENSORS)
        this->display();
}

void IMUSensor::reset() {
    this->accel_x = 0;
    this->accel_y = 0;
    this->accel_z = 0;
    this->gyro_x = 0;
    this->gyro_y = 0;
    this->gyro_z = 0;
    this->mag_x = 0;
    this->mag_y = 0;
    this->mag_z = 0;
    this->temp = 0;
}

void IMUSensor::display() {
    Serial.print("Accel X: ");
    Serial.print(this->accel_x);
    Serial.print(" | Accel Y: ");
    Serial.print(this->accel_y);
    Serial.print(" | Accel Z: ");
    Serial.print(this->accel_z);
    Serial.print(" | Temp: ");
    Serial.print(this->temp);
    Serial.print(" | Gyro X: ");
    Serial.print(this->gyro_x);
    Serial.print(" | Gyro Y: ");
    Serial.print(this->gyro_y);
    Serial.print(" | Gyro Z: ");
    Serial.print(this->gyro_z);
    Serial.print(" | Mag X: ");
    Serial.print(this->mag_x);
    Serial.print(" | Mag Y: ");
    Serial.print(this->mag_y);
    Serial.print(" | Mag Z: ");
    Serial.println(this->mag_z);
}

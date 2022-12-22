IMUSensor::IMUSensor() {
    this->accelX = 0;
    this->accelY = 0;
    this->accelZ = 0;
    this->gyroX = 0;
    this->gyroY = 0;
    this->gyroZ = 0;
    this->magX = 0;
    this->magY = 0;
    this->magZ = 0;
    this->temp = 0;
}

void IMUSensor::init() {
    this->working = true;
    Wire.begin();
    Wire.beginTransmission(IMU_ADDRESS);
    Wire.setWireTimeout(IMU_TIMEOUT, true);
    Wire.write(IMU_WRITE_REG_INIT);
    Wire.write(ZERO_REG);
    Wire.endTransmission(true);
}

void IMUSensor::update() {
    Wire.beginTransmission(IMU_ADDRESS);
    Wire.write(IMU_WRITE_REG_UPDATE);
    Wire.endTransmission(false);
    Wire.requestFrom(IMU_ADDRESS, IMU_REQUEST, true);
    this->accelX = Wire.read() << 8 | Wire.read();
    this->accelY = Wire.read() << 8 | Wire.read();
    this->accelZ = Wire.read() << 8 | Wire.read();
    this->temp = Wire.read() << 8 | Wire.read();
    this->gyroX = Wire.read() << 8 | Wire.read();
    this->gyroY = Wire.read() << 8 | Wire.read();
    this->gyroZ = Wire.read() << 8 | Wire.read();
    this->magX = Wire.read() << 8 | Wire.read();
    this->magY = Wire.read() << 8 | Wire.read();
    this->magZ = Wire.read() << 8 | Wire.read();
    if (DEBUG_SENSORS)
        this->display();
}

void IMUSensor::reset() {
    this->accelX = 0;
    this->accelY = 0;
    this->accelZ = 0;
    this->gyroX = 0;
    this->gyroY = 0;
    this->gyroZ = 0;
    this->magX = 0;
    this->magY = 0;
    this->magZ = 0;
    this->temp = 0;
}

void IMUSensor::display() {
    Serial.print("Accel X: ");
    Serial.print(this->accelX);
    Serial.print(" | Accel Y: ");
    Serial.print(this->accelY);
    Serial.print(" | Accel Z: ");
    Serial.print(this->accelZ);
    Serial.print(" | Temp: ");
    Serial.print(this->temp);
    Serial.print(" | Gyro X: ");
    Serial.print(this->gyroX);
    Serial.print(" | Gyro Y: ");
    Serial.print(this->gyroY);
    Serial.print(" | Gyro Z: ");
    Serial.print(this->gyroZ);
    Serial.print(" | Mag X: ");
    Serial.print(this->magX);
    Serial.print(" | Mag Y: ");
    Serial.print(this->magY);
    Serial.print(" | Mag Z: ");
    Serial.println(this->magZ);
}

MPU6050Sensor::MPU6050Sensor() {
    this->accelX = 0;
    this->accelY = 0;
    this->accelZ = 0;
    this->gyroX = 0;
    this->gyroY = 0;
    this->gyroZ = 0;
    this->mpu = new MPU6050();
}

void MPU6050Sensor::init() {
    this->working = true;
    this->mpu->initialize();
}

void MPU6050Sensor::update() {
    if (!this->working) return;
    this->mpu->getMotion6(&this->accelX, &this->accelY, &this->accelZ, &this->gyroX, &this->gyroY, &this->gyroZ);

    this->data = this->accelX;
}

void MPU6050Sensor::reset() {
    this->accelX = 0;
    this->accelY = 0;
    this->accelZ = 0;
    this->gyroX = 0;
    this->gyroY = 0;
    this->gyroZ = 0;
    this->init();
}

void MPU6050Sensor::display() {
    if (DEBUG_MPU) {
        Serial.print("Accel X: ");
        Serial.print(this->accelX);
        Serial.print(" | Accel Y: ");
        Serial.print(this->accelY);
        Serial.print(" | Accel Z: ");
        Serial.print(this->accelZ);
    }
}

void wireImplInit() {
    // Wire.begin();
    // Wire.beginTransmission(IMU_ADDRESS);
    // Wire.setWireTimeout(IMU_TIMEOUT, true);
    // Wire.write(IMU_WRITE_REG_INIT);
    // Wire.write(ZERO_REG);
    // Wire.endTransmission(true);
}

void wireImplUpdate() {
    // Wire.beginTransmission(IMU_ADDRESS);
    // Wire.write(IMU_WRITE_REG_UPDATE);
    // Wire.endTransmission(false);
    // Wire.requestFrom(IMU_ADDRESS, IMU_REQUEST, true);
    // this->accelX = Wire.read() << 8 | Wire.read();
    // this->accelY = Wire.read() << 8 | Wire.read();
    // this->accelZ = Wire.read() << 8 | Wire.read();
    // this->temp = Wire.read() << 8 | Wire.read();
    // this->gyroX = Wire.read() << 8 | Wire.read();
    // this->gyroY = Wire.read() << 8 | Wire.read();
    // this->gyroZ = Wire.read() << 8 | Wire.read();
    // this->magX = Wire.read() << 8 | Wire.read();
    // this->magY = Wire.read() << 8 | Wire.read();
    // this->magZ = Wire.read() << 8 | Wire.read();
}
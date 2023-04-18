MPU6050Sensor::MPU6050Sensor() {
  for (uint8_t i = 0; i < MPU_FRAME_SIZE; i++) {
    this->data[i] = 0;
  }
  this->mpu = new Adafruit_MPU6050();
}

void MPU6050Sensor::init() {
  this->working = true;
  if (!this->mpu->begin()) {
    Serial.println("MPU6050 not found");
    this->working = false;
  }
  this->mpu->setAccelerometerRange(MPU6050_RANGE_8_G);
  this->mpu->setGyroRange(MPU6050_RANGE_500_DEG);
  this->mpu->setFilterBandwidth(MPU6050_BAND_21_HZ);
  this->mpu->setMotionDetectionDuration(20);
  this->mpu->setMotionDetectionThreshold(10);
  this->mpu->setInterruptPinLatch(true);  // Keep it latched.  Will turn off when reinitialized.
  this->mpu->setInterruptPinPolarity(true);
  this->mpu->setMotionInterrupt(true);
}

void MPU6050Sensor::update() {
  if (!this->working) return;
  if (this->mpu->getMotionInterruptStatus()) {
    sensors_event_t accl, gyro, temp;
    this->mpu->getEvent(&accl, &gyro, &temp);
    this->data[0] = (uint8_t)(accl.acceleration.x * 100);
    this->data[1] = (uint8_t)(accl.acceleration.y * 100);
    this->data[2] = (uint8_t)(accl.acceleration.z * 100);
    this->data[3] = (uint8_t)(gyro.gyro.x * 100);
    this->data[4] = (uint8_t)(gyro.gyro.y * 100);
    this->data[5] = (uint8_t)(gyro.gyro.z * 100);
  }
}

void MPU6050Sensor::reset() {
  this->init();
}

uint8_t* MPU6050Sensor::getData() {
  return this->data;
}
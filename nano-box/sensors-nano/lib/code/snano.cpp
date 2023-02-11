SNano::SNano() {
  this->mpu = new MPU6050Sensor();
  this->pressure = new PressureSensor();
  this->uart = new UART(SENSORS_SOFTWARE_SERIAL_RX, SENSORS_SOFTWARE_SERIAL_TX);
}

void SNano::init() {
  this->mpu->init();
  this->pressure->init();
  this->uart->init();
}

void SNano::update() {
  this->mpu->update();
  this->pressure->update();
  this->frame[0] = this->mpu->getData();
  this->frame[1] = this->pressure->getData();
  this->uart->setFrameSent(this->frame);
  this->uart->send();
}
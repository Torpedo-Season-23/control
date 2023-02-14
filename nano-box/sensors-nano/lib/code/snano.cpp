SNano::SNano() {
  this->mpu = new MPU6050Sensor();
  this->pressure = new PressureSensor();
  this->uart = new UART(SENSORS_SOFTWARE_SERIAL_RX, SENSORS_SOFTWARE_SERIAL_TX);
  this->mapper = new SensorsMapper();
}

void SNano::init() {
  this->mpu->init();
  this->pressure->init();
  this->uart->init();
}

void SNano::update() {
  //* Get From Sensors
  this->mpu->update();
  this->pressure->update();
  this->mapper->setSensorsFrame(this->mpu->getData(), this->pressure->getData());

  //* Set Sensors Frame and Send
  this->uart->setFrameSent(this->mapper->getSensorsFrame());
}

void SNano::receive() {
  this->uart->receive();
}

void SNano::send() {
  this->uart->send();
}
MNano::MNano() {
  this->motion = new Motion6();
  this->uart = new UART(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);
}

void MNano::init() {
  this->uart->init();
  this->motion->init();
}

void MNano::update() {
  this->uart->receive();

  this->mapper->setData(this->uart->getFrameReceived());
  this->motion->setDirection(this->mapper->getDirection());
  this->motion->setSpeed(this->mapper->getSpeed());
  this->motion->setExponent(this->mapper->getExponent());

  this->motion->update();
}

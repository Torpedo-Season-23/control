MNANO::MNANO() {
  this->motion = new Motion6();
  this->uart = new UART(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);
}

void MNANO::init() {
  this->uart->init();
  this->motion->init();
}

void MNANO::update() {
  //* Receive Frame
  this->uart->receive();

  //* Set Frame To Motion
  this->mapper->setData(this->uart->getFrameReceived());
  this->motion->setDirection(this->mapper->getDirection());
  this->motion->setSpeed(this->mapper->getSpeed());
  this->motion->setExponent(this->mapper->getExponent());

  //* UPDATE MOTION
  this->motion->update();
}

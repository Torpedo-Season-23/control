MNANO::MNANO() {
  this->motion = new Motion6();
  this->uart = new UART(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);
}

void MNANO::init() {
  this->uart->init();
  this->motion->init();
}

void MNANO::update() {
  // TODO: Implement this
}

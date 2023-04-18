EUART::EUART() {
  this->uart = new UART(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);
}

void EUART::init() {
  this->uart->init();
}

void EUART::receive() {
  this->uart->receive();
  memcpy(this->frameReceived, this->uart->getFrameReceived(), UART_FRAME_RECEIVED_SIZE);
}

void EUART::send() {
  this->uart->setFrameSent(this->frameSent);
  this->uart->send();
}

void EUART::reset() {
  this->uart->reset();
}

void EUART::setFrameSent(uint8_t frame[UART_FRAME_SENT_SIZE]) {
  memcpy(this->frameSent, frame, UART_FRAME_SENT_SIZE);
}

uint8_t *EUART::getFrameReceived() {
  return this->frameReceived;
}
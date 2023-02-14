EUART::EUART() {
  this->sUart = new UART(SENSORS_SOFTWARE_SERIAL_RX, SENSORS_SOFTWARE_SERIAL_TX);
  this->mUart = new UART(MOTORS_SOFTWARE_SERIAL_RX, MOTORS_SOFTWARE_SERIAL_TX);
}

void EUART::init() {
  this->sUart->init();
  this->mUart->init();
}

void EUART::receive() {
  this->sUart->receive();
  memcpy(this->frameReceived, this->sUart->getFrameReceived(), UART_FRAME_RECEIVED_SIZE);
}

void EUART::send() {
  this->mUart->setFrameSent(this->frameSent);
  this->mUart->send();
}

void EUART::reset() {
  this->sUart->reset();
  this->mUart->reset();
}

void EUART::setFrameSent(uint8_t frame[UART_FRAME_SENT_SIZE]) {
  memcpy(this->frameSent, frame, UART_FRAME_SENT_SIZE);
}

uint8_t *EUART::getFrameReceived() {
  return this->frameReceived;
}
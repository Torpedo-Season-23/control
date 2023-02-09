UART::UART(uint8_t rxPin, uint8_t txPin) {
  this->softSerial = new SoftwareSerial(rxPin, txPin);
}

void UART::init() { this->softSerial->begin(SOFTWARE_SERIAL_BAUD_RATE); }

void UART::recieve() {
  this->softSerial->listen();
  if (this->softSerial->available()) {
    for (int i = 0; i < UART_FRAME_RECIEVED_SIZE; i++) {
      this->frameRecieved[i] = this->softSerial->read();
    }
  }
}

void UART::send() {
  this->softSerial->stopListening();
  for (int i = 0; i < UART_FRAME_SENT_SIZE; i++) {
    this->softSerial->write(this->frameSent[i]);
  }
}

void UART::reset() {
  for (int i = 0; i < UART_FRAME_RECIEVED_SIZE; i++) {
    this->frameRecieved[i] = 0;
  }
  for (int i = 0; i < UART_FRAME_SENT_SIZE; i++) {
    this->frameSent[i] = 0;
  }
}

void UART::update() {
  this->recieve();
  this->send();
}

void UART::setFrameSent(uint8_t frame[UART_FRAME_SENT_SIZE]) {
  for (int i = 0; i < UART_FRAME_SENT_SIZE; i++) {
    this->frameSent[i] = frame[i];
  }
}

uint8_t *UART::getFrameRecieved() { return this->frameRecieved; }

uint8_t *UART::getFrameSent() { return this->frameSent; }
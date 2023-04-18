UART::UART(uint8_t rxPin, uint8_t txPin) {
  this->softSerial = new SoftwareSerial(rxPin, txPin);
}

void UART::init() { this->softSerial->begin(BAUD_RATE); }

void UART::receive() {
  if (!this->softSerial->available())
    return;
  byte x = this->softSerial->read();
  if (x != RELIABLE_START_FRAME) {
    this->reset();
    return;
  }
  while (!this->softSerial->available())
    ;
  x = this->softSerial->read();
  if (x != RELIABLE_START_FRAME) {
    this->reset();
    return;
  }
  for (int i = 2; i < UART_FRAME_RECEIVED_SIZE - 2; i++) {
    while (!this->softSerial->available())
      ;
    frameReceived[i] = this->softSerial->read();
  }
  while (!this->softSerial->available())
    ;
  x = this->softSerial->read();
  if (x != RELIABLE_END_FRAME) {
    this->reset();
    return;
  }

  while (!this->softSerial->available())
    ;
  x = this->softSerial->read();
  if (x != RELIABLE_END_FRAME) {
    this->reset();
    return;
  }
}

void UART::send() {
  this->softSerial->write(frameSent, UART_FRAME_SENT_SIZE);
}

void UART::reset() {
  for (int i = 0; i < UART_FRAME_RECEIVED_SIZE; i++) {
    this->frameReceived[i] = 0;
  }
  for (int i = 0; i < UART_FRAME_SENT_SIZE; i++) {
    this->frameSent[i] = 0;
  }
}

void UART::update() {
  this->receive();
  this->send();
}

void UART::setFrameSent(uint8_t frame[UART_FRAME_SENT_SIZE]) {
  frameSent[0] = RELIABLE_START_FRAME;
  frameSent[1] = RELIABLE_START_FRAME;
  for (int i = 2; i < 2 + MPU_FRAME_SIZE + PRESSURE_FRAME_SIZE - 2; i++) {
    this->frameSent[i] = frame[i];
  }
  frameSent[UART_FRAME_SENT_SIZE - 1] = RELIABLE_END_FRAME;
  frameSent[UART_FRAME_SENT_SIZE - 2] = RELIABLE_END_FRAME;
}

uint8_t *UART::getFrameReceived() { return this->frameReceived; }

uint8_t *UART::getFrameSent() { return this->frameSent; }
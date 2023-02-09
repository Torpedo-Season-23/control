Mapper::Mapper() {
}

void Mapper::setEthernetRecievedFrame(uint8_t frame[ETHERNET_FRAME_RECIEVED_SIZE]) {
  for (int i = 0; i < ETHERNET_FRAME_RECIEVED_SIZE; i++) {
    this->ethernetRecievedFrame[i] = frame[i];
  }
  this->convertUartToEthernet();
}

void Mapper::setUartRecievedFrame(uint8_t frame[UART_FRAME_RECIEVED_SIZE]) {
  for (int i = 0; i < UART_FRAME_RECIEVED_SIZE; i++) {
    this->uartRecievedFrame[i] = frame[i];
  }
  this->convertEthernetToUart();
}

uint8_t *Mapper::getEthernetSentFrame() {
  return this->ethernetSentFrame;
}

uint8_t *Mapper::getUartSentFrame() {
  return this->uartSentFrame;
}

void Mapper::convertEthernetToUart() {
  // TODO: Implement
}

void Mapper::convertUartToEthernet() {
  // TODO: Implement
}
Mapper::Mapper() {
}

void Mapper::setEthernetReceivedFrame(uint8_t frame[ETHERNET_FRAME_RECEIVED_SIZE]) {
  for (int i = 0; i < ETHERNET_FRAME_RECEIVED_SIZE; i++) {
    this->ethernetReceivedFrame[i] = frame[i];
  }
  this->convertUartToEthernet();
}

void Mapper::setUartReceivedFrame(uint8_t frame[UART_FRAME_RECEIVED_SIZE]) {
  for (int i = 0; i < UART_FRAME_RECEIVED_SIZE; i++) {
    this->uartReceivedFrame[i] = frame[i];
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
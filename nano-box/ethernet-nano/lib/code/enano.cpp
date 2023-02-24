ENano::ENano() {
  this->uart = new EUART();
  this->ethernet = new BoxEthernet();
  this->mapper = new Mapper();
}

void ENano::init() {
  this->ethernet->init();
  this->uart->init();
}

void ENano::update() {
  this->ethernet->receive();
  this->mapper->setEthernetReceivedFrame(this->ethernet->getFrameReceived());
  this->uart->setFrameSent(this->mapper->getUartSentFrame());
  this->uart->send();

  this->ethernet->send();
}

void ENano::getSensors() {
  digitalWrite(SENSOR_INTERRUPT_PIN, LOW);
  this->uart->receive();
  digitalWrite(SENSOR_INTERRUPT_PIN, HIGH);
  this->mapper->setUartReceivedFrame(this->uart->getFrameReceived());
  this->ethernet->setFrameSent(this->mapper->getEthernetSentFrame());
}
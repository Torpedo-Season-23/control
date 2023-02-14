ENANO::ENANO() {
  this->uart = new EUART();
  this->ethernet = new BoxEthernet();
  this->mapper = new Mapper();
}

void ENANO::init() {
  this->ethernet->init();
  this->uart->init();
}

void ENANO::update() {
  // * Receiving Process
  this->ethernet->receive();
  this->mapper->setEthernetReceivedFrame(this->ethernet->getFrameReceived());
  this->uart->setFrameSent(this->mapper->getUartSentFrame());
  this->uart->send();

  this->ethernet->send();
}

void ENANO::getSensors() {
  this->uart->receive();
  this->mapper->setUartReceivedFrame(this->uart->getFrameReceived());
  this->ethernet->setFrameSent(this->mapper->getEthernetSentFrame());
}
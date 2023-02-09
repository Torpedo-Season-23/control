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
  // * Recieve Process
  this->ethernet->recieve();
  this->mapper->setEthernetRecievedFrame(ethernet->getFrameRecieved());
  this->uart->setFrameSent(this->mapper->getUartSentFrame());
  this->uart->send();

  // * Sent Process
  this->uart->recieve();
  this->mapper->setUartRecievedFrame(this->uart->getFrameRecieved());
  this->ethernet->setFrameSent(this->mapper->getEthernetSentFrame());
  this->ethernet->send();
}
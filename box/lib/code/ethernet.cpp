
EthernetModule::EthernetModule() {
    this->mac[0] = ETHERNET_MAC_0;
    this->mac[1] = ETHERNET_MAC_1;
    this->mac[2] = ETHERNET_MAC_2;
    this->mac[3] = ETHERNET_MAC_3;
    this->mac[4] = ETHERNET_MAC_4;
    this->mac[5] = ETHERNET_MAC_5;
    this->ip[0] = ETHERNET_IP_0;
    this->ip[1] = ETHERNET_IP_1;
    this->ip[2] = ETHERNET_IP_2;
    this->ip[3] = ETHERNET_IP_3;
    this->console[0] = ETHERNET_CONSOLE_0;
    this->console[1] = ETHERNET_CONSOLE_1;
    this->console[2] = ETHERNET_CONSOLE_2;
    this->console[3] = ETHERNET_CONSOLE_3;
    this->port = ETHERNET_PORT;
}

void EthernetModule::init() {
}

void EthernetModule::update() {
    this->recieve();
    this->send();
}

void EthernetModule::recieve() {
}

void EthernetModule::send() {
}

void EthernetModule::reset() {
}

void EthernetModule::display() {
}

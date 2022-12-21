
EthernetModule::EthernetModule() {
    this->mac[0] = ETHERNET_MAC_0;
    this->mac[1] = ETHERNET_MAC_1;
    this->mac[2] = ETHERNET_MAC_2;
    this->mac[3] = ETHERNET_MAC_3;
    this->mac[4] = ETHERNET_MAC_4;
    this->mac[5] = ETHERNET_MAC_5;
    this->ip = IPAddress(IP_0, IP_1, IP_2, ETHERNET_BOX_3);
    this->console = IPAddress(IP_0, IP_1, IP_2, ETHERNET_CONSOLE_3);
    this->port = ETHERNET_PORT;
}

void EthernetModule::init() {
    Ethernet.begin(this->mac, this->ip);
    // TODO: implement
}

void EthernetModule::reset() {
    for (int i = 0; i < FRAME_RECIEVED_SIZE; i++) {
        this->frameRecieved[i] = 0;
    }
    for (int i = 0; i < FRAME_SENT_SIZE; i++) {
        this->frameSent[i] = 0;
    }
    this->init();
}

void EthernetModule::display() {
    Serial.print("Ethernet: ");
    Serial.print("MAC: ");
    for (int i = 0; i < MAC_COUNT; i++) {
        Serial.print(this->mac[i]);
        if (i < MAC_COUNT - 1) {
            Serial.print(":");
        }
    }
    Serial.print(" | IP: ");
    for (int i = 0; i < IP_COUNT; i++) {
        Serial.print(this->ip[i]);
        if (i < IP_COUNT - 1) {
            Serial.print(".");
        }
    }
    Serial.print(" | Console: ");
    for (int i = 0; i < IP_COUNT; i++) {
        Serial.print(this->console[i]);
        if (i < IP_COUNT - 1) {
            Serial.print(".");
        }
    }
    Serial.print(" | Port: ");
    Serial.println(this->port);
}

void EthernetModule::setFrameSent(uint8_t frame[FRAME_SENT_SIZE]) {
    for (int i = 0; i < FRAME_SENT_SIZE; i++) {
        this->frameSent[i] = frame[i];
    }
}

uint8_t* EthernetModule::getFrameRecieved() {
    return this->frameRecieved;
}

uint8_t* EthernetModule::getFrameSent() {
    return this->frameSent;
}

void EthernetModule::recieve() {
    // TODO: implement
}

void EthernetModule::send() {
    // TODO: Implement
}

EthernetModule::EthernetModule() {
    this->mac[0] = ETHERNET_MAC_0;
    this->mac[1] = ETHERNET_MAC_1;
    this->mac[2] = ETHERNET_MAC_2;
    this->mac[3] = ETHERNET_MAC_3;
    this->mac[4] = ETHERNET_MAC_4;
    this->mac[5] = ETHERNET_MAC_5;
    this->ip = IPAddress(ETHERNET_IP_0, ETHERNET_IP_1, ETHERNET_IP_2, ETHERNET_IP_3);
    this->console = IPAddress(ETHERNET_CONSOLE_0, ETHERNET_CONSOLE_1, ETHERNET_CONSOLE_2, ETHERNET_CONSOLE_3);
    this->port = ETHERNET_PORT;
}

void EthernetModule::init() {
    Ethernet.begin(this->mac, this->ip);
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
    for (int i = 0; i < FRAME_RECIEVED_SIZE; i++) {
        this->frameRecieved[i] = 0;
    }
    for (int i = 0; i < FRAME_SENT_SIZE; i++) {
        this->frameSent[i] = 0;
    }
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
    Serial.print(" IP: ");
    for (int i = 0; i < IP_COUNT; i++) {
        Serial.print(this->ip[i]);
        if (i < IP_COUNT - 1) {
            Serial.print(".");
        }
    }
    Serial.print(" Console: ");
    for (int i = 0; i < IP_COUNT; i++) {
        Serial.print(this->console[i]);
        if (i < IP_COUNT - 1) {
            Serial.print(".");
        }
    }
    Serial.print(" Port: ");
    Serial.println(this->port);
}

void EthernetModule::setFrameRecieved(uint8_t frame[FRAME_RECIEVED_SIZE]) {
    for (int i = 0; i < FRAME_RECIEVED_SIZE; i++) {
        this->frameRecieved[i] = frame[i];
    }
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
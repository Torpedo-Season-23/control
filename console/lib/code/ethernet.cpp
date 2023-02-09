ConsoleEthernet::ConsoleEthernet() {
    this->mac[0] = ETHERNET_CONSOLE_MAC_0;
    this->mac[1] = ETHERNET_CONSOLE_MAC_1;
    this->mac[2] = ETHERNET_CONSOLE_MAC_2;
    this->mac[3] = ETHERNET_CONSOLE_MAC_3;
    this->mac[4] = ETHERNET_CONSOLE_MAC_4;
    this->mac[5] = ETHERNET_CONSOLE_MAC_5;
    this->boxIp = IPAddress(IP_0, IP_1, IP_2, BOX_IP_3);
    this->consoleIp = IPAddress(IP_0, IP_1, IP_2, CONSOLE_IP_3);
    this->udp = new EthernetUDP();
    this->packetSize = 0;
    for (uint8_t i = 0; i < FRAME_RECIEVED_SIZE; i++) {
        this->frameRecieved[i] = 0;
    }
    for (uint8_t i = 0; i < FRAME_SENT_SIZE; i++) {
        this->frameSent[i] = 0;
    }
}

void ConsoleEthernet::init() {
    Ethernet.begin(this->mac, this->consoleIp);
    this->udp->begin(CONSOLE_PORT);
    this->lastTimeRecieved = millis();
}

void ConsoleEthernet::reset() {
    for (int i = 0; i < FRAME_RECIEVED_SIZE; i++) {
        this->frameRecieved[i] = 0;
    }
    for (int i = 0; i < FRAME_SENT_SIZE; i++) {
        this->frameSent[i] = 0;
    }
    this->init();
}

void ConsoleEthernet::setFrameSent(uint8_t frame[FRAME_SENT_SIZE]) {
    for (int i = 0; i < FRAME_SENT_SIZE; i++) {
        this->frameSent[i] = frame[i];
    }
}

uint8_t* ConsoleEthernet::getFrameRecieved() {
    return this->frameRecieved;
}

uint8_t* ConsoleEthernet::getFrameSent() {
    return this->frameSent;
}

void ConsoleEthernet::recieve() {
    this->packetSize = this->udp->parsePacket();
    if (this->packetSize == FRAME_RECIEVED_SIZE) {
        udp->read(this->frameRecieved, this->packetSize);
        this->lastTimeRecieved = millis();
    } else {
        if (millis() - this->lastTimeRecieved > CRITICAL_TIME) {
            this->reset();
        }
    }
}

void ConsoleEthernet::send() {
    this->udp->beginPacket(this->consoleIp, CONSOLE_PORT);
    this->udp->write(this->frameSent, FRAME_SENT_SIZE);
    this->udp->endPacket();
}

void ConsoleEthernet::update() {
    this->recieve();
    this->send();
    if (DEBUG_ETHERNET)
        this->display();
}

void ConsoleEthernet::display() {
    if (SHOW_MAC_AND_IP) {
        Serial.print("MAC: ");
        for (int i = 0; i < MAC_COUNT; i++) {
            Serial.print(this->mac[i]);
            if (i < MAC_COUNT - 1) {
                Serial.print(":");
            }
        }
        Serial.print(" | Box IP: ");
        for (int i = 0; i < IP_COUNT; i++) {
            Serial.print(this->boxIp[i]);
            if (i < IP_COUNT - 1) {
                Serial.print(".");
            }
        }
        Serial.print(" | Box Port: ");
        Serial.print(BOX_PORT);

        Serial.print(" | Console IP: ");
        for (int i = 0; i < IP_COUNT; i++) {
            Serial.print(this->consoleIp[i]);
            if (i < IP_COUNT - 1) {
                Serial.print(".");
            }
        }
        Serial.print(" | Console Port: ");
        Serial.print(CONSOLE_PORT);
    }

    SHOW_MAC_AND_IP == 1 ? Serial.print(" | Frame recieved: ") : Serial.print("Frame recieved: ");
    for (int i = 0; i < FRAME_RECIEVED_SIZE; i++) {
        Serial.print(this->frameRecieved[i]);
        if (i < FRAME_RECIEVED_SIZE - 1) {
            Serial.print(" ");
        }
    }

    Serial.print(" | Frame sent: ");
    for (int i = 0; i < FRAME_SENT_SIZE; i++) {
        Serial.print(this->frameSent[i]);
        if (i < FRAME_SENT_SIZE - 1) {
            Serial.print(" ");
        }
    }
    Serial.println();
}
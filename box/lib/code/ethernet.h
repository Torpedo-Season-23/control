#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#include <UIPEthernet.h>

#include "communication.h"

class EthernetModule : public Communication {
   private:
    uint8_t mac[MAC_COUNT];
    IPAddress ip;
    IPAddress console;
    unsigned int port;
    EthernetUDP udp;
    void display();

   public:
    EthernetModule();
    virtual void init();
    virtual void reset();
    virtual void setFrameSent(uint8_t frame[FRAME_SENT_SIZE]);
    virtual uint8_t* getFrameRecieved();
    virtual uint8_t* getFrameSent();
    virtual void recieve();
    virtual void send();
};

#ifndef _ETHERNET_CPP_
#include "ethernet.cpp"
#endif

#endif
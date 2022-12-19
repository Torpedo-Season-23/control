#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#include <UIPEthernet.h>

#include "communication.h"
#include "config.h"

class EthernetModule : public Communication {
   private:
    uint8_t mac[MAC_COUNT];
    IPAddress ip;
    IPAddress console;
    unsigned int port;
    EthernetUDP udp;
    uint8_t frameRecieved[FRAME_RECIEVED_SIZE];
    uint8_t frameSent[FRAME_SENT_SIZE];
    void display();

   public:
    EthernetModule();
    virtual void init();
    virtual void update();
    virtual void reset();
    void setFrameRecieved(uint8_t frame[FRAME_RECIEVED_SIZE]);
    void setFrameSent(uint8_t frame[FRAME_SENT_SIZE]);
    uint8_t* getFrameRecieved();
    uint8_t* getFrameSent();
    virtual void recieve();
    virtual void send();
};

#ifndef _ETHERNET_CPP_
#include "ethernet.cpp"
#endif

#endif
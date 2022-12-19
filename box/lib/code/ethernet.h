#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#include <UIPEthernet.h>

#include "communication.h"
#include "config.h"

class EthernetModule : public Communication {
   private:
    unsigned int mac[MAC_COUNT];
    unsigned int ip[IP_COUNT];
    unsigned int console[IP_COUNT];
    unsigned int port;
    // TODO: make frame
    void display();

   public:
    EthernetModule();
    virtual void init();
    virtual void update();
    virtual void reset();
    virtual void recieve();
    virtual void send();
};

#ifndef _ETHERNET_CPP_
#include "ethernet.cpp"
#endif

#endif
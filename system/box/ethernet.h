#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#include "communication.h"
#include "config.h"
#include "lib/UIPEthernet/UIPEthernet.h"

class Ethernet : public Communication {
   private:
    UIPEthernet *ethernet;
    // TODO: make frame
    void dispaly();

   public:
    Ethernet();
    virtual void init();
    virtual void update();
    virtual void recieve();
    virtual void send();
};

#endif
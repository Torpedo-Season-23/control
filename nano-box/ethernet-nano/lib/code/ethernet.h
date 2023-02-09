#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#include <UIPEthernet.h>

#include "communication.h"

class BoxEthernet : public Communication {
 private:
  uint8_t frameRecieved[ETHERNET_FRAME_RECIEVED_SIZE];
  uint8_t frameSent[ETHERNET_FRAME_SENT_SIZE];
  uint8_t mac[MAC_COUNT];
  IPAddress boxIp;
  IPAddress consoleIp;
  EthernetUDP* udp;
  uint8_t packetSize;
  unsigned long lastTimeRecieved;
  void display();

 public:
  BoxEthernet();
  virtual void init();
  virtual void reset();
  virtual void update();
  virtual void setFrameSent(uint8_t frame[ETHERNET_FRAME_SENT_SIZE]);
  virtual uint8_t* getFrameRecieved();
  virtual uint8_t* getFrameSent();
  virtual void recieve();
  virtual void send();
};

#ifndef _ETHERNET_CPP_
#include "ethernet.cpp"
#endif

#endif
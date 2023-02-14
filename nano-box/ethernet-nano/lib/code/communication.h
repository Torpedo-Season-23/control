#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include "config.h"

class Communication {
 public:
  virtual void init() = 0;
  virtual void receive() = 0;
  virtual void send() = 0;
  virtual void reset() = 0;
  virtual void update() = 0;
  virtual uint8_t *getFrameReceived() = 0;
  virtual uint8_t *getFrameSent() = 0;
};

#endif

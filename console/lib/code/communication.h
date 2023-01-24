#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include "config.h"

class Communication {
   protected:
    uint8_t frameSent[FRAME_SENT_SIZE];
    uint8_t frameRecieved[FRAME_RECIEVED_SIZE];

   public:
    virtual void init() = 0;
    virtual void recieve() = 0;
    virtual void send() = 0;
    virtual void reset() = 0;
    virtual void update() = 0;
    virtual void setFrameSent(uint8_t frame[FRAME_SENT_SIZE]) = 0;
    virtual uint8_t *getFrameRecieved() = 0;
    virtual uint8_t *getFrameSent() = 0;
};

#endif

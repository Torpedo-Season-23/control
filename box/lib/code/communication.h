#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

class Communication {
   public:
    virtual void init() = 0;
    virtual void recieve() = 0;
    virtual void send() = 0;
    virtual void reset() = 0;
    virtual void setFrameSent(uint8_t *frame) = 0;
    virtual uint8_t *getFrameRecieved() = 0;
    virtual uint8_t *getFrameSent() = 0;
};

#endif

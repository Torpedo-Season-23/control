#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

class Communication {
  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void recieve() = 0;
    virtual void send() = 0;
    virtual void reset() = 0;
};

#endif

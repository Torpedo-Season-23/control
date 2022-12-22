#ifndef _ACCESSORIES_H_
#define _ACCESSORIES_H_

#include "config.h"

class Accessories {
   private:
    uint8_t pins[ACCESSORIES_COUNT];
    uint8_t data;

   public:
    Accessories();
    void init();
    void update();
    void reset();
    void setAccessories(uint8_t frame);
    uint8_t getAccessories();
};

#ifndef _ACCESSORIES_CPP_
#include "accessories.cpp"
#endif

#endif
#ifndef _MAPPER_H_
#define _MAPPER_H_

#include "config.h"

class Mapper {
   public:
    static DIRECTION getDirection(uint8_t *frame);
    static float getSpeed(uint8_t *frame);
    static uint8_t *getAccessories(uint8_t *frame);
};

#ifndef _MAPPER_CPP_
#include "mapper.cpp"
#endif

#endif
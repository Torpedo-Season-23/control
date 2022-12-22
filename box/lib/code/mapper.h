#ifndef _MAPPER_H_
#define _MAPPER_H_

#include "config.h"

class Mapper {
   public:
    static DIRECTION getDirection(uint8_t *communicationFrame);
    static uint8_t *getSpeed(uint8_t *communicationFrame);
    static uint8_t getAccessories(uint8_t *communicationFrame);
    static SENSOR_TYPE getSensorToToggle(uint8_t accessoriesFrame);
};

#ifndef _MAPPER_CPP_
#include "mapper.cpp"
#endif

#endif
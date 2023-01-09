#ifndef _MAPPER_H_
#define _MAPPER_H_

#include "config.h"

class Mapper {
   private:
    uint8_t data[FRAME_RECIEVED_SIZE];
    DIRECTION direction;
    uint16_t speed[MOTOR_COUNT];
    uint8_t exponent[EXPONENT_COUNT];
    uint8_t accessories;
    SENSOR_TYPE sensorToToggle;

   public:
    void setData(uint8_t *communicationFrame);
    void setDirection();
    void setSpeed();
    void setExponent();
    void setAccessories();
    void setSensorToToggle();
    SENSOR_TYPE getSensorToToggle();
    DIRECTION getDirection();
    uint16_t *getSpeed();
    uint8_t *getExponent();
    uint8_t getAccessories();
};

#ifndef _MAPPER_CPP_
#include "mapper.cpp"
#endif

#endif
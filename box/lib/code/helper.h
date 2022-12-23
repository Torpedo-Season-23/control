#ifndef _HELPER_H_
#define _HELPER_H_

#include "config.h"

class Helper {
   public:
    static char const* getDirection(DIRECTION direction);
    static char const* getMotorType(MOTOR_ORIENTATION type);
    static char const* getSensorType(SENSOR_TYPE type);
    static char const* getAccessoriesType(ACCESSORIES_TYPE type);
    static char const* getOnOff(uint8_t value);
};

#ifndef _HELPER_CPP_
#include "helper.cpp"
#endif

#endif
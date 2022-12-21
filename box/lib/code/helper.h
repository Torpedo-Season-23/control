#ifndef _HELPER_H_
#define _HELPER_H_

#include "config.h"

class Helper {
   public:
    static char const* getDirection(DIRECTION direction);
    static char const* getCurrentSensorType(CURRENT_SENSOR_TYPE type);
};

#ifndef _HELPER_CPP_
#include "helper.cpp"
#endif

#endif
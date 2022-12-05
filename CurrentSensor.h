#include<Arduino.h>
#ifndef CURRENTSENSOR_H
#define CURRENTSENSOR_H
#define VIN A0
#define vcc 5.0

class CurrentSensor {
  public:
    uint8_t current;
    uint8_t getCurrent();
    
};
#endif

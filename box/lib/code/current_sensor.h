#ifndef _CURRENT_SENSOR_H_
#define _CURRENT_SENSOR_H_

#include "config.h"
#include "sensor.h"

class CurrentSensor : public Sensor {
   private:
    unsigned char pin;
    float current;
    SENSOR_TYPE type;

   public:
    CurrentSensor(unsigned char pin, SENSOR_TYPE type);
    virtual void init();
    virtual void update();
    virtual void reset();
    float getCurrent();
    virtual void display();
};

#ifndef _CURRENT_SENSOR_CPP_
#include "current_sensor.cpp"
#endif

#endif
#ifndef _SENSOR_H_
#define _SENSOR_H_

class Sensor {
   public:
    bool working;
    Sensor() {
        working = false;
    };
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void reset() = 0;
    virtual toggleWorking() {
        working = !working;
    };
};

#endif
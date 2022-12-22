#ifndef _SENSOR_H_
#define _SENSOR_H_

class Sensor {
   public:
    bool working;
    Sensor() {
        this->working = false;
    };
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void reset() = 0;
    virtual void startWorking() {
        this->working = true;
    };
    virtual void stopWorking() {
        this->working = false;
    };
    virtual void toggleWorking() {
        this->working = !this->working;
    };
};

#endif
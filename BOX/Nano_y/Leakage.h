#ifndef LEAKAGE_H
#define LEAKAGE_H


#include <Arduino.h>

class LeakageSensor{
    private:
    float temperature;
    float humidity;
    //byte sensor_num;

    public:
    LeakageSensor();
    void init();
    void update();
    //void setByte(int i);
    uint8_t getHumidity();
    uint8_t getTemperature();
    //uint8_t getSensorNum();

};

#endif
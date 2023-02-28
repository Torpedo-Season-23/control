#ifndef LEAKAGE_H
#define LEAKAGE_H

#define DHTPIN 2 
#define DHTTYPE DHT22  
#define SENSORS_NUM 8

#include <Arduino.h>

class LeakageSensor{
    private:
    float temperature;
    float humidity;
    byte sensor_num;

    public:
    LeakageSensor();
    void init();
    void update();
    void setSensor(int i);
    uint8_t getHumidity();
    uint8_t getTemperature();
    uint8_t getSensorNum();

};

#endif
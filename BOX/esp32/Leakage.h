#ifndef LEAKAGE_H
#define LEAKAGE_H
#include <Arduino.h>
#include "config.h"

class LeakageSensor {
private:
  float temperature[SENSORS_NUM];
  uint8_t humidity[SENSORS_NUM];

public:
  LeakageSensor();
  void init();
  void update();
  uint8_t* getHumidity();
  uint8_t* getTemperature();
};

#endif
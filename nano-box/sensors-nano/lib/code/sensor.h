#ifndef _SENSOR_H_
#define _SENSOR_H_

class Sensor {
 protected:
  bool working;

 public:
  Sensor();
  virtual void init() = 0;
  virtual void update() = 0;
  virtual void reset() = 0;
  virtual void startWorking();
  virtual void stopWorking();
  virtual void toggleWorking();
};

#ifndef _SENSOR_CPP_
#include "sensor.cpp"
#endif

#endif
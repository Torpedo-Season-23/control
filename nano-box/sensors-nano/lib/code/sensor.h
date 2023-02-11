#ifndef _SENSOR_H_
#define _SENSOR_H_

class Sensor {
 protected:
  float data;
  bool working;

 public:
  Sensor();
  virtual void init() = 0;
  virtual void update() = 0;
  virtual void reset() = 0;
  virtual float getData();
  virtual void startWorking();
  virtual void stopWorking();
  virtual void toggleWorking();
  virtual void display() = 0;
};

#ifndef _SENSOR_CPP_
#include "sensor.cpp"
#endif

#endif
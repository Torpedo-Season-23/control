#ifndef _PRESSURE_SENSOR_H_
#define _PRESSURE_SENSOR_H_

#include "../SoftSPi/SoftSPI.h"
#include "config.h"
#include "sensor.h"

class PressureSensor : public Sensor {
 private:
  unsigned char mclk;
  unsigned char miso;
  unsigned char mosi;
  unsigned char sclk;
  SoftSPI *spi;
  float pressure;
  float temperature;
  float depth;
  uint16_t readData(const uint16_t command, const unsigned long recvDelay = 0);

 public:
  PressureSensor();
  virtual void init();
  virtual void update();
  virtual void reset();
  float getDepth();
  float getPressure();
  virtual void display();
};

#ifndef _PRESSURE_SENSOR_CPP_
#include "pressure_sensor.cpp"
#endif

#endif
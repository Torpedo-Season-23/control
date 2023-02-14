#ifndef _SNANO_H_
#define _SNANO_H_

#include "config.h"
#include "mapper.h"
#include "mpu_sensor.h"
#include "pressure_sensor.h"
#include "uart.h"

class SNano {
 private:
  MPU6050Sensor *mpu;
  PressureSensor *pressure;
  UART *uart;
  SensorsMapper *mapper;

 public:
  SNano();
  void init();
  void update();
  void receive();
  void send();
};

#ifndef _SNANO_CPP_
#include "snano.cpp"
#endif

#endif
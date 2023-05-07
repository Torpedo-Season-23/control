#ifndef _MAPPER_H_
#define _MAPPER_H_

#include "config.h"

class SensorsMapper {
 private:
  uint8_t sensorsFrame[SENSORS_FRAME_SIZE];

 public:
  SensorsMapper();
  void setSensorsFrame(uint8_t mpuFrame[MPU_FRAME_SIZE], uint8_t pressureFrame[PRESSURE_FRAME_SIZE]);
  uint8_t *getSensorsFrame();
};

#ifndef _MAPPER_CPP_
#include "mapper.cpp"
#endif

#endif
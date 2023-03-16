#ifndef UART_Z_H
#define UART_Z_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Config.h"


class Uartz {
public:
  uint8_t uartFrame[ACTUAL_DATA];
  void startUart();
  void receiveFrame();
  void extractData(uint16_t* thrustersFrame, uint8_t* toolsFrame);
};





#endif

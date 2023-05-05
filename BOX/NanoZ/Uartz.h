#ifndef UART_Z_H
#define UART_Z_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Config.h"


class Uartz {
public:
  uint8_t uartFrame[8];
  void startUart();
  void receiveFrame();
  void sendFrame();
  void extractData(uint16_t* thrustersFrame, uint8_t* toolsFrame);
  inline byte readByte();
};

#endif

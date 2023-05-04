#ifndef UART_H
#define UART_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "config.h"


class UART_YZ {
public:
  UART_YZ(){};
  void begin();
  void receiveFrame(uint8_t* frame);
  void sendFrame(uint8_t*);
private:
  inline byte readByte();
};
#endif

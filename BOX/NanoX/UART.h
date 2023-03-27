#ifndef UART_H
#define UART_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "config.h"


class UART_YZ {
private:
  uint8_t rec_frame[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
public:
  UART_YZ(){};
  int counter = 0;
  void begin();
  void receiveFrame(uint8_t* frame);
  void sendFrame(uint8_t*);
private:
  inline byte readByte();
};
#endif
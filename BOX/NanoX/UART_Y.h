#ifndef UART_Y_H
#define UART_Y_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "config.h"


class UART_Y{
  private:
  uint8_t rec_frame[8];
    public:
        UART_Y(){};
        void begin();
        void receiveFrame(uint8_t* frame);
        void sendFrame(uint8_t*);
};
#endif

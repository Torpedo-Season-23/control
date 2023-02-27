#ifndef UART_Z_H
#define UART_Z_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Config.h"


class Uart_z{
  public:
  void startUART();  
  void receiveFrame(uint8_t* , uint8_t* );
  void extractData(uint8_t frame[] , uint8_t* , uint8_t* );

};





#endif

#ifndef UART_Z_H
#define UART_Z_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#define UART_Z_FRAME_SIZE 18// 2 gaurd |1 directions | 6 Motor| 6 exponent | 1 Accessories | 2 gaurd 
#define ACTUAL_DATA 14 // ( 1 directions | 6 Motor| 6 exponent | 1 Accessories )
#define THRUSTERSFRAME 13
#define TOOLSFRAME 8 
#define RX_Z 25
#define TX_Z 24


class Uart_z{
  public:
  void startUART();  
  void receiveFrame(uint8_t* , uint8_t* );
  void extractData(uint8_t frame[] , uint8_t* , uint8_t* );

};





#endif
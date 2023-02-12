#ifndef UART_Z_H
#define UART_Z_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Output_signals.h"

#define UART_Z_FRAME_SIZE 18       // (2 gaurd |1 directions | 6 Motor| 6 exponent | 1 Accessories | 2 gaurd )(bytes)
#define ACTUAL_DATA 14             // ( 1 directions | 6 Motor| 6 exponent | 1 Accessories )(bytes)
#define THRUSTERS_FRAME 13         //bytes
#define THRUSTERS_signal_FRAME 18  //( 6 directions | 6 Motor | 6 exp )(elements)
#define TOOLS_FRAME 4     
#define RX_Z 9
#define TX_Z 8


class Uart_z{
  public:
  void startUART();  
  void receiveFrame(uint8_t* , uint8_t* );
  void extractData(uint8_t frame[] , uint8_t* , uint8_t* );

};





#endif

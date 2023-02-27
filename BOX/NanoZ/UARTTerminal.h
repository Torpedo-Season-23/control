#ifndef UART_Z_H
#define UART_Z_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Output_signals.h"

#define UART_Z_FRAME_SIZE 10      // (1 gaurd |1 directions | 6 Motor| 1 Accessories | 1 gaurd )(bytes) waiting for sensors....
#define ACTUAL_DATA 8             // ( 1 directions | 6 Motor | 1 Accessories )(bytes) waiting......
// #define NANOZ_DATA_INDEX unkown
#define THRUSTERS_ACC_FRAME 13     //bytes
#define THRUSTERS_FRAME 12         //( 6 directions | 6 Motor)(elements)
#define TOOLS_FRAME 8    
// #define MOTORS_SPEEDS_INDEX unkown
// #define DIRECTIONS_BYTE_INDEX unkown
// #define ACC_BYTE_INDEX unkown
#define RX_Z 9
#define TX_Z 8



class Uart_z{
  public:
  void startUART();  
  void receiveFrame(uint8_t* , uint8_t* );
  void extractData(uint8_t frame[] , uint8_t* , uint8_t* );

};





#endif

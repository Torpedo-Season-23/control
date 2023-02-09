#ifndef _E_UART_H_
#define _E_UART_H_

#include "uart.h"

class EUART {
 private:
  UART *sUart;
  UART *mUart;
  uint8_t frameRecieved[UART_FRAME_RECIEVED_SIZE];
  uint8_t frameSent[UART_FRAME_SENT_SIZE];
  uint8_t sensorsFrame[SENSORS_FRAME_SIZE];
  uint8_t motorsFrame[MOTORS_FRAME_SIZE];

 public:
  EUART();
  void init();
  void recieve();
  void send();
  void reset();
  void setFrameSent(uint8_t frame[UART_FRAME_SENT_SIZE]);
  uint8_t *getFrameRecieved();
};

#ifndef _E_UART_CPP_
#include "euart.cpp"
#endif

#endif
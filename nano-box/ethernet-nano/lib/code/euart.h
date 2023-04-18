#ifndef _E_UART_H_
#define _E_UART_H_

#include "uart.h"

class EUART {
 private:
  UART *uart;
  uint8_t frameReceived[UART_FRAME_RECEIVED_SIZE];
  uint8_t frameSent[UART_FRAME_SENT_SIZE];

 public:
  EUART();
  void init();
  void receive();
  void send();
  void reset();
  void setFrameSent(uint8_t frame[UART_FRAME_SENT_SIZE]);
  uint8_t *getFrameReceived();
};

#ifndef _E_UART_CPP_
#include "euart.cpp"
#endif

#endif
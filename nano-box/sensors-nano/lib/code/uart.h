#ifndef _UART_H_
#define _UART_H_

#include "../SoftwareSerial/src/SoftwareSerial.h"
#include "communication.h"

class UART : public Communication {
 private:
  SoftwareSerial *softSerial;
  uint8_t frameRecieved[UART_FRAME_RECIEVED_SIZE];
  uint8_t frameSent[UART_FRAME_SENT_SIZE];

 public:
  UART(uint8_t rxPin, uint8_t txPin);
  void init();
  void recieve();
  void send();
  void reset();
  void update();
  void setFrameSent(uint8_t frame[UART_FRAME_SENT_SIZE]);
  uint8_t *getFrameRecieved();
  uint8_t *getFrameSent();
};

#ifndef _UART_CPP_
#include "uart.cpp"
#endif

#endif
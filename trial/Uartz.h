#ifndef UART_Z_H
#define UART_Z_H
typedef unsigned char uint8_t;
// typedef unsigned int uint16_t;


class Uartz {
public:
  unsigned char uartFrame[8];
  void receiveFrame(uint8_t *frame);
  void extractData(unsigned int* thrustersFrame, uint8_t* toolsFrame);
};

#endif

#ifndef _MAPPER_H_
#define _MAPPER_H_

#include "config.h"

class Mapper {
 private:
  uint8_t ethernetRecievedFrame[ETHERNET_FRAME_RECEIVED_SIZE];
  uint8_t ethernetSentFrame[ETHERNET_FRAME_SENT_SIZE];
  uint8_t uartRecievedFrame[UART_FRAME_RECEIVED_SIZE];
  uint8_t uartSentFrame[UART_FRAME_SENT_SIZE];
  void convertEthernetToUart();
  void convertUartToEthernet();

 public:
  Mapper();
  void setEthernetReceivedFrame(uint8_t frame[ETHERNET_FRAME_RECEIVED_SIZE]);
  void setUartReceivedFrame(uint8_t frame[UART_FRAME_RECEIVED_SIZE]);
  uint8_t *getEthernetSentFrame();
  uint8_t *getUartSentFrame();
};

#ifndef _MAPPER_CPP_
#include "mapper.cpp"
#endif

#endif
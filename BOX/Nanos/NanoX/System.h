#include "communication.h"
#include "UART.h"
#include "config.h"


class System {
private:
  CommunicationClient client;
  UART_YZ uart_yz;
  uint8_t udpReceiveFrame[UDP_REC_FRAME]{0};
  uint8_t udpSendFrame[UDP_SEND_FRAME] = { 0 };
 
public:
  System(){};
  void init();
  void sendData();
  void receiveData();
  void activateUART();
};

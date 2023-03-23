#include "communication.h"
#include "Converter.h"
#include "UART_Y.h"
#include "config.h"


class System {
private:
  CommunicationClient client;
  UART_Y uart_y;
  //Converter converter;
  uint8_t udpReceiveFrame[UDP_REC_FRAME] {255 , 255 ,180 ,180 ,0 ,0 ,0 ,0 };
  uint8_t udpSendFrame[UDP_SEND_FRAME] = {0};

public:
  System(){};
  void init();
  void sendData();
  void receiveData();
  void activateUART();
  void useData();  //for converters
};

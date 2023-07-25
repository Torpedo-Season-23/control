#include "Thrusters.h"
#include "Tools.h"
#include "communication.h"

class System {
private:
  CommunicationClient client;
  // UART_YZ uart_yz;
  uint8_t udpReceiveFrame[UDP_REC_FRAME]{0};
  uint8_t udpSendFrame[UDP_SEND_FRAME] = { 0 };
  Thrusters thrusters;
  Thruster thruster;
  Tools tools;
  void extractData(uint16_t *thrustersFrame, uint8_t *toolsFrame);

public:
  System(){};
  void init();
  void sendData();
  void receiveData();
  void getData();
  void setData();
};

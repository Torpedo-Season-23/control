#include "Thrusters.h"
#include "Tools.h"
#include "communication.h"
#include "TorpedoMPU.h"
#include "Pressure.h"
#include "Leakage.h"

class System {
private:
  CommunicationClient client;
  uint8_t udpReceiveFrame[UDP_REC_FRAME] = { 0 };
  uint8_t udpSendFrame[UDP_SEND_FRAME] = { 0 };
  
  TorpedoMPU IMU;

  Thrusters thrusters;
  Tools tools;

  void extractData(uint16_t *thrustersFrame, bool *toolsFrame);

public:
  System(){};
  void init();
  void sendData();
  void receiveData();
  void getData();
  void setData();
  void prepareData();
};

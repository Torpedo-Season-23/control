#include "Thrusters.h"
#include "Tools.h"
#include "communication.h"
#include "config.h"
#include "ISensor.h"
#include "IMU.h"
#include "Pressure.h"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>


class System {
private:
  CommunicationClient client;
  uint8_t udpReceiveFrame[UDP_REC_FRAME] = { 0 };
  uint8_t udpSendFrame[UDP_SEND_FRAME] = { 0 };
  Thrusters thrusters;
  Tools tools;
  AsyncWebServer server;
  IMU *imu;
  Pressure *pressure;
  const char *ssid = "esp";
  const char *password = "12345678";
  void extractData(uint16_t *thrustersFrame, bool *toolsFrame);
  void init_wifi_services();
  void prepareData();
public:
  System()
    : server(80) {
    this->imu = new IMU();
    this->pressure = new Pressure();
  }
  ~System(){
    delete this->imu;
    delete this->pressure;
    delete this->udpSendFrame;
    delete this->udpReceiveFrame;
  }
  void init();
  void sendData();
  void receiveData();
  void motorToolsUpdate();
  void sensorsUpdate();
  uint8_t *getUdpReceiveFrame();
  uint8_t *getUdpSendFrame();
  void setToolsFrame(bool * arr);
};

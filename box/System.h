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
#include <AsyncTCP.h>
#include <Arduino_JSON.h>
#include "SPIFFS.h"


class System {
private:
  IMU *imu;
  Tools tools;
  JSONVar readings;
  Pressure *pressure;
  Thrusters thrusters;
  AsyncWebServer server;
  AsyncEventSource events;
  CommunicationClient client;
  const char *ssid = "esp";
  const char *password = "12345678";
  void init_spiffs();
  void prepareData();
  void init_wifi_services();
  uint8_t udpSendFrame[UDP_SEND_FRAME] = { 0 };
  uint8_t udpReceiveFrame[UDP_REC_FRAME] = { 0 };
  void extractData(uint16_t *thrustersFrame, bool *toolsFrame);
public:
  System()
    : server(80) ,events("/events") , tools(33,32,17){
    this->imu = new IMU();
    this->pressure = new Pressure();
  }
  ~System() {
    delete this->imu;
    delete this->pressure;
    delete this->udpSendFrame;
    delete this->udpReceiveFrame;
  }
  void init();
  void sendData();
  void receiveData();
  void sensorsUpdate();
  void motorToolsUpdate();
  uint8_t *getUdpReceiveFrame();
  uint8_t *getUdpSendFrame();
  void setToolsFrame(bool *arr);
  void setThrusterFrame(int arr);
};

#include "System.h"
#include <AsyncElegantOTA.h>


void System::init() {
  this->client.init();
  this->client.defaultFrame(udpReceiveFrame);
  this->tools.init();
  // this->thrusters.init();
  // this->imu->init();
  this->pressure->init();
  this->init_wifi_services();
}
void System::sensorsUpdate() {
  // this->imu->update();
  this->pressure->update();
  // this->pressure->display();
}

void System::motorToolsUpdate() {
  this->thrusters.update();
  this->tools.update();
}


void System::sendData() {
  this->prepareData();
  client.sendData(udpSendFrame);
}

void System::receiveData() {
  client.receiveData(udpReceiveFrame);
  this->extractData(this->thrusters.thrustersFrame, this->tools.getToolsFrame());
}

void System::setToolsFrame(bool *arr) {
  this->tools.setToolsFrame(arr);
}

void System::init_wifi_services() {
  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(IPAddress(192, 168, 1, 190), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  this->server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });
  AsyncElegantOTA.begin(&server);  // Start ElegantOTA
  WebSerial.begin(&server);
  server.begin();
  Serial.println("HTTP server started");
}
void System::prepareData() {
  int sensorFrame[5] = { 0 };
  int temp = (int)((float)(this->pressure->getTemprature() + this->imu->getTemprature()) / 2.0);
  for (int i = 0; i < 3; i++) {
    sensorFrame[i] = this->imu->getAngles()[i];
  }
  sensorFrame[3] = 1023;//this->pressure->getPressure();
  sensorFrame[4] = 29;
  int j = 0;
  for (int i = 0; i < UDP_SEND_FRAME; i += 2) {
    this->udpSendFrame[i] = highByte(sensorFrame[j]);
    this->udpSendFrame[i + 1] = lowByte(sensorFrame[j]);
    j++;
  }
}

void System::extractData(uint16_t *thrustersFrame, bool *toolsFrame) {
  //extract Accessories data
  for (int i = 0; i < TOOLS_COUNT; i++) {
    if (udpReceiveFrame[ACC_BYTE_INDEX] & 1 == 1) {
      toolsFrame[i] = HIGH;
    } else {
      toolsFrame[i] = LOW;
    }
    udpReceiveFrame[ACC_BYTE_INDEX] >>= 1;
  }

  //extract Thrusters Speeeds
  int j = 0;
  for (int i = 1; i < ACTUAL_DATA; i += 2) {
    uint16_t speedValue = (udpReceiveFrame[i + 1] << 8) | udpReceiveFrame[i];

    if (speedValue > MOT_MAX_SPEED) speedValue = MOT_MAX_SPEED;
    if (speedValue < MOT_MIN_SPEED) speedValue = MOT_MIN_SPEED;

    thrustersFrame[j] = speedValue;
    j++;
  }

//Debuging
#ifdef THRUSTERS_PRINT_ON
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Serial.print(thrustersFrame[i]);
    Serial.print(" ");
  }
  Serial.println();
#endif
  //Debuging
#ifdef ACC_PRINT_ON
  for (int i = 0; i < TOOLS_COUNT; i++) {
    Serial.print(toolsFrame[i]);
    Serial.print("--");
  }
  Serial.println();
#endif
}
uint8_t *System::getUdpReceiveFrame() {
  return this->udpReceiveFrame;
}
uint8_t *System::getUdpSendFrame() {
  return this->udpSendFrame;
}

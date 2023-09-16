#include "System.h"
#include <AsyncElegantOTA.h>




void System::init() {
  this->client.init();
  this->client.defaultFrame(udpReceiveFrame);
  this->tools.init();
  this->thrusters.init();
  this->imu->init();
  this->pressure->init();
  this->init_wifi_services();
  // this->init_spiffs();
}
void System::sensorsUpdate() {
  this->imu->update();
  //  this->imu->display();
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


  // this->server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
  //   request->send(SPIFFS, "/index.html", "text/html");
  // });
  // server.serveStatic("/", SPIFFS, "/");
  AsyncElegantOTA.begin(&server);  // Start ElegantOTA
  WebSerial.begin(&server);

  server.begin();
  Serial.println("HTTP server started");
}

void System::init_spiffs() {
  if (!SPIFFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  Serial.println("SPIFFS mounted successfully");
}

void System::prepareData() {
  int sensorFrame[5] = { 0 };
  int temp = (int)((float)(this->pressure->getTemprature() + this->imu->getTemprature()) / 2.0);
  for (int i = 0; i < 3; i++) {
    sensorFrame[i] = this->imu->getAngles()[i];
  }
  sensorFrame[3] = this->pressure->getPressure();  //this->pressure->getPressure();
  sensorFrame[4] = temp;
  int j = 0;
  for (int i = 0; i < UDP_SEND_FRAME; i += 2) {
    this->udpSendFrame[i] = highByte(sensorFrame[j]);
    this->udpSendFrame[i + 1] = lowByte(sensorFrame[j]);
    j++;
  }
}

void System::extractData(uint16_t *thrustersFrame, bool *toolsFrame) {
  //extract Accessories data

  Serial.print("pins : ");
  // WebSerial.print("pins : ");
  // Serial.println(this->client.toolbyte);
  int x=this->client.toolbyte;
  for (int i = 0; i < TOOLS_COUNT; i++) {
    if (x & 1 == 1) {
      toolsFrame[i] = HIGH;
    } else {
      toolsFrame[i] = LOW;
    }
    x >>= 1;
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
  // #ifdef THRUSTERS_PRINT_ON
  //   for (int i = 0; i < MOTORS_COUNT; i++) {
  //     Serial.print(thrustersFrame[i]);
  //     Serial.print(" ");
  //   }
  //   Serial.println();
  // #endif
  //   //Debuging
  // #ifdef ACC_PRINT_ON
    for (int i = 0; i < TOOLS_COUNT; i++) {
      Serial.print(toolsFrame[i]);
      // WebSerial.print(toolsFrame[i]);
      Serial.print("--");
      // WebSerial.print("--");
    }
    Serial.println();
    // WebSerial.println();
  // #endif
}
uint8_t *System::getUdpReceiveFrame() {
  return this->udpReceiveFrame;
}
uint8_t *System::getUdpSendFrame() {
  return this->udpSendFrame;
}




void System::setThrusterFrame(int arr) {
  for (int i = 0; i < 6; i++) {
    this->thrusters.thrustersFrame[i]=arr;
  }
}
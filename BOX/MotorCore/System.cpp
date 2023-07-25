#include "System.h"
void System::init() {
  this->client.init();
  this->client.defaultFrame(udpReceiveFrame);
  tools.init();
  thrusters.init();
}

void System::getData() {
  extractData(thrusters.thrustersFrame, tools.toolsFrame);
}

void System::setData() {
  thrusters.applySignal();
  tools.applySignal();
}


void System::sendData() {
  client.sendData(udpSendFrame);
}

void System::receiveData() {
  bool i = client.receiveData(udpReceiveFrame);
}


void System::extractData(uint16_t *thrustersFrame, uint8_t *toolsFrame) {
  //extract Accessories data
  for (int i = 0; i < TOOLS_COUNT; i++) {
    if (udpReceiveFrame[ACC_BYTE_INDEX] & 1 == 1) {
      toolsFrame[i] = 1;
    } else {
      toolsFrame[i] = 0;
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

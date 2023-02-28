#ifndef SYSTEM_H
#define SYSTEM_H

#include "IController.h"
#include "Thrusters.h"
#include "communication.h"
#include "psgamepad.h"
#include "lf310.h"
#include <Arduino.h>


uint8_t receivedFrame[22];
uint8_t sentFrame[8];

class System {
private:
  Thrusters thruster;
  IController* gamepad;
  Communication console;
public:
  System(IController* gamepad) {
    this->gamepad = gamepad;
  }
  void Init();
  void Update();
};



void System::Init() {
  this->gamepad->init();
  this->console.comm_init();
}

void System ::Update() {
  gamepad->Update();
  int speed = gamepad->getspeed();
  int* array = gamepad->get_hframe();
  int* v = gamepad->get_vframe();
  int* acc = gamepad->get_accframe();
  thruster.set_h_forces(gamepad->get_hframe());
  thruster.set_v_forces(gamepad->get_vframe());
  int* res = thruster.get_thruster_frame();

  int converters[2] = { 1, 1 };
  this->console.prepareData(acc, res, converters, sentFrame);
  this->console.sendData(sentFrame);

  this->console.receiveData(receivedFrame);
  int16_t* sensors;
  this->console.getSensors(receivedFrame, sensors);

  // Serial.println();
  // Serial.print("array frame  ");
  // Serial.print(array[0]);
  // Serial.print("--");
  // Serial.print(array[1]);
  // Serial.print("--");
  // Serial.print(array[2]);
  // Serial.print("speed  ");
  // Serial.println(speed);
  // Serial.println();
  // Serial.print("vertical ");
  // Serial.print(v[0]);
  // Serial.print("--");
  // Serial.print(v[1]);
  // Serial.println();
  // Serial.print("acc frame  ");
  // Serial.print(acc[0]);
  // Serial.print("--");
  // Serial.print(acc[1]);
  // Serial.print("--");
  // Serial.print(acc[2]);
  // Serial.print("--");
  // Serial.print(acc[3]);
  //UR , BR , UL ,BL , UP , DOWN
  // Serial.println();
  // Serial.print("UR: ");
  // Serial.println(res[1]);
  // Serial.print("BR: ");
  // Serial.println(res[0]);
  // Serial.print("UL: ");
  // Serial.println(res[3]);
  // Serial.print("BL: ");
  // Serial.println(res[2]);
  // Serial.print("UP: ");
  // Serial.println(res[4]);
  // Serial.print("DOWN: ");
  // Serial.println(res[5]);
}


#endif
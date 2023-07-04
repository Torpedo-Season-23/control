#ifndef SYSTEM_H
#define SYSTEM_H

#include "IController.h"
#include "Thrusters.h"
#include "communication.h"
#include "psgamepad.h"
#include "lf310.h"
#include "SoftStart.h"
#include "IndexConverter.h"
#include "factors.h"
#include "LCD.h"




class System {
  private:
    Thrusters thruster;
    Motors motors;
    IController* gamepad;
    Communication console;
    IndexConverter indexConverter;
    Factor factor;
    LCD lcd;
  public:
    System(IController* gamepad) {
      this->gamepad = gamepad;
    }
    void Init();
    void Update();
    void updateRTC();
    void clearLCD();
};


void System::updateRTC(){
  this->lcd.updateRTC();
}
void System:: clearLCD(){
  this->lcd.clear();
}
void System::Init() {
  this->gamepad->init();
  this->console.comm_init();
  this->indexConverter.init(thruster.get_thruster_frame());
  this->lcd.init();
}
void System::Update() {
  bool attach = this->gamepad->force_stop();
  uint8_t receivedFrame[receivedFrameSize];
  this->gamepad->Update();
  int speed = this->gamepad->getspeed();
  int* array = this->gamepad->get_hframe();
  int* v = this->gamepad->get_vframe();
  int* acc = this->gamepad->get_accframe();
  thruster.speed = this->gamepad->getspeed();
  thruster.set_h_forces(this->gamepad->get_hframe());
  thruster.set_v_forces(this->gamepad->get_vframe());
  int* res;
  res = thruster.get_thruster_frame();


  res = indexConverter.updateArray();

  this->factor.getFactor(this->gamepad->getDirection(), thruster.speed , res);
  motors.update(res);


  uint8_t sentFrame[16];
  int16_t sensors[SENSORS];
  this->console.prepareData(acc, res, sentFrame, attach);
  this->console.receiveData(receivedFrame);
  this->console.sendData(sentFrame);
  this->lcd.update(sensors , acc , this->gamepad->getspeed() , this->gamepad->getDirection());
}




#endif

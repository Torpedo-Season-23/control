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




class System {
private:
  Thrusters thruster;
  Motors motors;
  IController* gamepad;
  Communication console;
  IndexConverter indexConverter;
  Factor factor;
  
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
  
  this->indexConverter.init(thruster.get_thruster_frame());

}
void System::Update() {
  uint8_t receivedFrame[receivedFrameSize];
  this->gamepad->Update();
  // int speed = this->gamepad->getspeed();
  int* array = this->gamepad->get_hframe();
  int* v = this->gamepad->get_vframe();
  int* acc = this->gamepad->get_accframe();
  thruster.speed= this->gamepad->getspeed();
  // int testarray[3]={128,0,0};
  thruster.set_h_forces(this->gamepad->get_hframe());
  thruster.set_v_forces(this->gamepad->get_vframe());
  int* res;
  res = thruster.get_thruster_frame();
  /*Serial.println(speed);
  if (speed ==100)
  for(int i= 0;i<6;i++)
    res[i]= 1800;
  if (speed ==250)
  for(int i= 0;i<6;i++)
    res[i]= 1500;
  if (speed ==400)
  for(int i= 0;i<6;i++)
    res[i]= 1600;*/
  
  
  
  res= indexConverter.updateArray();
  this->factor.getFactor(this->gamepad->getDirection(), thruster.speed , res);
  motors.update(res);
 
 
  Serial.print("Thrusters: ");
  for(int i= 0;i<6;i++){
    Serial.print(res[i]);
    Serial.print(" ");
  }
  Serial.println();
  
  this->gamepad->getDirection();
  Serial.println();

  uint8_t sentFrame[16];
  int16_t sensors[SENSORS];
  this->console.prepareData(acc, res, sentFrame);
  this->console.receiveData(receivedFrame);
  this->console.sendData(sentFrame);
  this->console.getSensors(receivedFrame, sensors);
  }

#endif

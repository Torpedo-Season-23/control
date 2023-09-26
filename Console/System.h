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
#include "PID.h"




class System {
private:
  Thrusters thruster;
  Motors motors;
  IController* gamepad;
  Communication console;
  IndexConverter indexConverter;
  Factor factor;
  LCD lcd;
  PID pidv;
  PID pidh;
  float fact[4] = { 1, 1, 1, 1 };
  int k = 0;
  long time = 0;
  long prev = 0;
  bool is = true;
  int arr[6];
  int acs[8];
  void swap(int* arr);
public:
  System(IController* gamepad)
    : pidv(gamepad, 40, 0, 1),pidh(gamepad, 10, 0, 0)  {
    this->gamepad = gamepad;
  }
  void Init();
  void Update();
  void updateRTC();
  void clearLCD();
};


void System::updateRTC() {
  this->lcd.updateRTC();
}
void System::clearLCD() {
  this->lcd.clear();
}
void System::Init() {
  this->time = millis();
  this->gamepad->init();
  this->console.comm_init();
  this->indexConverter.init(thruster.get_thruster_frame());
  this->lcd.init();
  for (int i = 0; i < 6; i++) this->arr[i] = 1500;
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
  int16_t sensors[5];
  this->console.receiveData(receivedFrame, sensors);
  // Serial.print("yaw:  ");
  // for(int i=3;i<4;i++){
  // if(sensors[3]<1700)
  // Serial.println(sensors[2]);
  //   Serial.print("  ");
  // }
  // Serial.println();
  // pid.setPIDFactors(fact);
  // pid.updateDepth(sensors[3]);
  // pidh.update(sensors[2]);




  thruster.set_h_forces(this->gamepad->get_hframe());
  thruster.set_v_forces(this->gamepad->get_vframe());
  int* res;
  res = thruster.get_thruster_frame();


  if (Serial.available()) {
    float x = Serial.parseFloat();
    // if(x!=0){
    fact[k % 4] = x;
    k++;
  }
  // // Serial.print("Motors : ");
  for (int i = 0; i < 4; i++) {
    Serial.print(fact[i]);
    Serial.print("  ");
  }
  Serial.println();
  // Serial.print("pressure : ");
  // Serial.println();

  // this->factor.setFactors(this->gamepad->getDirection(), thruster.speed, fact);
  this->factor.getFactor(this->gamepad->getDirection(), thruster.speed, res);
  // motors.update(res);
  swap(res);
  // this->indexConverter.init(res);
  // res = indexConverter.updateArray();
  // motors.print();
  // Serial.println();
  // Serial.print("Tools : ");
  // for (int i=0; i<8;i++){
  //   Serial.print(acc[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();
  // int h=Serial.read()-48;
  // if (h==0){
  //   for (int i=0;i<8;i++){
  //   this->acs[i]=1;
  //   this->arr[i]=1800;
  //   }
  //   Serial.println("all grippers on");
  // }
  // else if(h==1){
  //   for (int i=0;i<8;i++){
  //   this->acs[i]=0;
  //   this->arr[i]=1500;}
  //   Serial.println("all grippers off");
  // }

  // if (this->time-this->prev>3000){
  //     this->prev=millis();
  //     if(this->is){
  //       this->is=false;
  //       for(int i=0;i<6;i++)
  //       this->arr[i]=1500;
  //     }
  //     else{
  //       is=true;
  //       for(int i=0;i<6;i++)
  //       this->arr[i]=1800;
  //     }
  // }
  uint8_t sentFrame[13];

  this->console.prepareData(acc, res, sentFrame, attach);
  this->console.sendData(sentFrame);
  // this->lcd.update(sensors , acc , this->gamepad->getspeed() , this->gamepad->getDirection());
}


void System::swap(int* arr) {
  int temp = arr[0];
  arr[0] = arr[4];
  arr[4] = temp;
}

#endif

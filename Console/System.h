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
    float fact[4]={1};
    int k=0;
    long time=0;
    long prev=0;
    bool is=true;
    int arr[6];
    int acs[8];
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
  this->time=millis();
  this->gamepad->init();
  this->console.comm_init();
  this->indexConverter.init(thruster.get_thruster_frame());
  this->lcd.init();
  for(int i=0;i<6;i++)this->arr[i]=1500;
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
  
  
  if(Serial.available()){
    float x =Serial.parseFloat();
    fact[k%4]=x;
    k++;
  }
  for(int i=0;i<4;i++){Serial.print(fact[i]);
  Serial.print("  ");
  }

  this->factor.setFactors(this->gamepad->getDirection(), thruster.speed, fact);
  this->factor.getFactor(this->gamepad->getDirection(), thruster.speed , res);
  motors.update(res);
  // motors.print();
  // Serial.println();
  // Serial.print("Tools : ");
  // for (int i=0; i<8;i++){
  //   Serial.print(acc[i]);
  //   Serial.print(" ");
  // }
  Serial.println();
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
  // res = indexConverter.updateArray();

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
  int16_t sensors[SENSORS];
  this->console.prepareData(acc,res, sentFrame, attach);
  this->console.receiveData(receivedFrame);
  this->console.sendData(sentFrame);
  // this->lcd.update(sensors , acc , this->gamepad->getspeed() , this->gamepad->getDirection());
}




#endif

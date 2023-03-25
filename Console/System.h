#ifndef SYSTEM_H
#define SYSTEM_H

#include "IController.h"
#include "Thrusters.h"
#include "communication.h"
#include "psgamepad.h"
#include "lf310.h"





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
void System::Update() {
  uint8_t receivedFrame[16];
  this->gamepad->Update();
  int speed = this->gamepad->getspeed();
  int* array = this->gamepad->get_hframe();
  int* v = this->gamepad->get_vframe();
  int* acc = this->gamepad->get_accframe();
  thruster.set_h_forces(this->gamepad->get_hframe());
  thruster.set_v_forces(this->gamepad->get_vframe());
  int* res;
  res = thruster.get_thruster_frame();

  //int acc[20] = {0};
 

  uint8_t sentFrame[16];
  this->console.prepareData(acc, res, sentFrame);
  this->console.sendData(sentFrame);



  this->console.receiveData(receivedFrame);

  int16_t* sensors;

  this->console.getSensors(receivedFrame, sensors);



  // for(int i = 0 ; i <THRUSTERS ;  i++){
  //   Serial.print( *(res+i) );
  //   Serial.print("\t");
  // }

  // Serial.println("---------------------------------------");
  //double* res -> int16_t* thrusters

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
  // // Serial.print(v[1]);
  // Serial.println();
  // Serial.print("acc frame  ");
  // Serial.print(acc[0]);
  // Serial.print("--");
  // Serial.print(acc[1]);
  // Serial.print("--");
  // Serial.print(acc[2]);
  // Serial.print("--");
  // Serial.print(acc[3]);
  // Serial.print("--");
  // Serial.print(acc[4]);
  // Serial.print("--");
  // Serial.print(acc[5]);
  // Serial.print("--");
  // Serial.print(acc[6]);
  // Serial.print("--");
  // Serial.print(acc[7]);

  //UR , BR , UL ,BL , UP , DOWN
  Serial.println();
  Serial.print("UR: ");
  Serial.println(res[1]);
  Serial.print("BR: ");
  Serial.println(res[0]);
  Serial.print("UL: ");
  Serial.println(res[3]);
  Serial.print("BL: ");
  Serial.println(res[2]);
  Serial.print("UP: ");
  Serial.println(res[4]);
  Serial.print("DOWN: ");
  Serial.println(res[5]);
  Serial.print("Sensors:  ");
  // for (int i =0 ; i < 16; i++) {
  // Serial.print(receivedFrame[i]);
  // Serial.print(" ");
  // }
  // Serial.println();
}


#endif
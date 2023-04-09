#ifndef SYSTEM_H
#define SYSTEM_H

#include "IController.h"
#include "Thrusters.h"
#include "communication.h"
#include "psgamepad.h"
#include "lf310.h"
#include "SoftStart.h"
#include "IndexConverter.h"





class System {
private:
  Thrusters thruster;
  Motors motors;
  IController* gamepad;
  Communication console;
  IndexConverter indexConverter;
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
  
  motors.update(res);
  res= indexConverter.updateArray();

  /*Serial.print("Thrusters: ");
  for(int i= 0;i<6;i++){
    Serial.print(res[i]);
    Serial.print(" ");
  }
  Serial.println();*/
  

  uint8_t sentFrame[16];
  this->console.prepareData(acc, res, sentFrame);
  this->console.receiveData(receivedFrame);
  /*Serial.print("Frame to be sent: ");
  for(int i= 0;i<8;i++){
    Serial.print(sentFrame[i]);
    Serial.print("\t");
  }
  Serial.println();*/
  this->console.sendData(sentFrame);




  int16_t sensors[SENSORS];

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
 /* Serial.println();
  Serial.print("UR: ");
  Serial.print(res[1]);
  Serial.print("\t");
  Serial.print("BR: ");
  Serial.print(res[0]);
  Serial.print("\t");
  Serial.print("UL: ");
  Serial.print(res[2]);
  Serial.print("UP: ");
  Serial.print("\t");
  Serial.print(res[4]);
  Serial.print("\t");
  Serial.print("DOWN: ");
  Serial.println(res[5]);*/
  //Serial.print("Sensors:  ");
  // for (int i =0 ; i < 16; i++) {
  // Serial.print(receivedFrame[i]);
  // Serial.print(" ");
  // }
  // Serial.println();
}


#endif

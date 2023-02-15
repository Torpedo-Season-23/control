#include "System.h"


Xbox controller;
IController *gamepad;
System s (&controller);
// Communication console;
// ThrustersProcess config;
void setup() {
  Serial.begin(115200);
  // gamepad=&controller;
  // gamepad->init();
  s.Init();
  // console.comm_init();
}

void loop() {
  s.Update();

  // gamepad->Update();
  // int speed = gamepad->getspeed();
  // int* array = gamepad->get_hframe();
  // int* v = gamepad->get_vframe();
  // int * acc = gamepad->get_accframe();
  // thruster.set_h_forces(gamepad->get_hframe());
  // thruster.set_v_forces(gamepad->get_vframe());
  // double* res;
  // res = thruster.get_thruster_frame();


  // // uint8_t* sentFrame;
  // // prepareData(acc, res, sentFrame);
  // // sendData(sentFrame);

  // // uint8_t* receivedFrame;
  // // receiveData(receivedFrame);

  // // int16_t* sensors;
  // // getSensors(receivedFrame, sensors);

  // //double* res -> int16_t* thrusters

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
  // //UR , BR , UL ,BL , UP , DOWN
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
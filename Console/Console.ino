#include "controller.h"
#include "Thrusters.h"

Controller controller;
Thrusters thruster;
// ThrustersProcess config;
void setup() {
  Serial.begin(115200);
  // controller.init();
  // config.processForces(128, 0, 0);
  float arr[3]={128,0,0};
  float array[2]={0,1900};
  double* res;
  thruster.set_h_forces(arr);
  thruster.set_v_forces(array);
  res=thruster.get_thruster_frame();
  //UR , BR , UL ,BL , UP , DOWN
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




}

void loop() {
 


 
  // int speed=controller.getspeed();
  // int* array=controller.getframe();
  // int* v=controller.get_vframe();
  // uint8_t* acc=controller.get_accframe();
  // controller.Update();
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

  




}
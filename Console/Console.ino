#include "controller.h"
#include "Thrusters.h"

Controller controller;
Thrusters thruster;
Thrusters t;
// ThrustersProcess config;
void setup() {
  Serial.begin(115200);
  controller.init();

}

void loop() {
 


 
  int speed=controller.getspeed();
  int* array=controller.get_hframe();
  int* v=controller.get_vframe();
  int arr[3]={128,0,0};
  float arra[2]={0,1900};
  uint8_t* acc=controller.get_accframe();

  controller.Update();
  thruster.set_h_forces(array);
  thruster.set_v_forces(v);
  double * res;
  res=thruster.get_thruster_frame();
  Serial.println();
  Serial.print("array frame  ");
  Serial.print(array[0]);
  Serial.print("--");
  Serial.print(array[1]);
  Serial.print("--");
  Serial.print(array[2]);
  Serial.print("speed  ");
  Serial.println(speed);
  Serial.println();
  Serial.print("vertical ");
  Serial.print(v[0]);
  Serial.print("--");
  Serial.print(v[1]);
  Serial.println();
  Serial.print("acc frame  ");
  Serial.print(acc[0]);
  Serial.print("--");
  Serial.print(acc[1]);
  Serial.print("--");
  Serial.print(acc[2]);
  Serial.print("--");
  Serial.print(acc[3]);
  // //UR , BR , UL ,BL , UP , DOWN
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

  




}
#include "Thrusters.h"
#include <Arduino.h>

int *Thrusters::get_thruster_frame(){
  return this->thruster_frame;
}

void Thrusters::set_h_forces(int *array){
  for(int i=0;i<4;i++)this->thruster_frame[i]=0;
  for(int i = 0; i < 4; ++i){
    for(int j = 0; j< 3; ++j)this->thruster_frame[i]+= this->config_matrix[i][j] * array[j];
    // Serial.println(this->thruster_frame[i]);
    this->thruster_frame[i]=map(this->thruster_frame[i],-45,45,1100,1900);
  }
  // free(array);
}

void Thrusters::set_v_forces(int *array){
  this->thruster_frame[4]=array[0];
  this->thruster_frame[5]=array[1];
  // free(array);
} 

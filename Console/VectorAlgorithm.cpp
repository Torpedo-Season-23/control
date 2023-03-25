#include "VectorAlgorithm.h"
#include <Arduino.h>
int *VectorAlgorithm::get_thruster_frame(){
  return this->thruster_frame;
}

void VectorAlgorithm::set_h_forces(int *array){
  for(int i=0;i<4;i++)
    this->thruster_frame[i]=0;
  for(char i = 0; i < 4; ++i){
    for(int j = 0; j< 3; ++j)
      this->thruster_frame[i]+= this->config_matrix[i][j] * array[j];
    this->thruster_frame[i]=map(this->thruster_frame[i],-45,45,1100,1900);
  }
}

void VectorAlgorithm::set_v_forces(int *array){
  this->thruster_frame[Up]=array[0];
  this->thruster_frame[Down]=array[1];
} 

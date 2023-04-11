#include "Thrusters.h"
#include "SoftStart.h"
#include <Arduino.h>


int *Thrusters::get_thruster_frame() {
  return this->thruster_frame;
}

void Thrusters::set_h_forces(int *array) {
  int16_t maxNumber= 0;
 
  for (int i = 0; i < 4; i++) 
    this->thruster_frame[i] = 0;
  for (char i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) 
      this->thruster_frame[i] += this->config_matrix[i][j] * array[j];
    
    maxNumber= max(abs(this->thruster_frame[i]),maxNumber);
7    //this->thruster_frame[i] = map(this->thruster_frame[i], -36, 36, 1100, 1900);
    //print frame after softstart
    // delay(100);
  }
  if(!maxNumber)this->speed= 0;
    //Serial.println("Zeros");
  for (int i = 0; i < 4; i++) 
    this->thruster_frame[i] = map(this->thruster_frame[i], -1*maxNumber, maxNumber, 1500-this->speed, 1500+this->speed);
  
  
  // free(array);
}

void Thrusters::set_v_forces(int *array) {
  this->thruster_frame[4] = array[0];
  this->thruster_frame[5] = array[1];
  // Serial.print(this->thruster_frame[4]);
  // Serial.print("  ");

  // Serial.print(this->thruster_frame[4]);
  // Serial.print("\t");

  // Serial.print(this->thruster_frame[5]);
  // Serial.print("  ");


  // Serial.print(this->thruster_frame[5]);
  //   Serial.print("\t");
  // free(array);
}

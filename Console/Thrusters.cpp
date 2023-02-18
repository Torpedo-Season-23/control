#include "Thrusters.h"
#include "softStart.h"
#include <Arduino.h>

int motor_controlled_speed[MOTORS_COUNT] = {0};

int *Thrusters::get_thruster_frame(){
  return this->thruster_frame;
}

void Thrusters::set_h_forces(int *array){
  for(int i=0;i<4;i++)this->thruster_frame[i]=0;
  for(char i = 0; i < 4; ++i){
    for(int j = 0; j< 3; ++j)this->thruster_frame[i]+= this->config_matrix[i][j] * array[j];
    // Serial.println(this->thruster_frame[i]);
    this->thruster_frame[i]=map(this->thruster_frame[i],-45,45,1100,1900);
    //print frame before softstart
    Serial.print(this->thruster_frame[i]);
    Serial.print("  ");  
    
    motor_soft_start (this->thruster_frame[i], (motor_controlled_speed+i) ,  this->thruster_frame , i);
    //print frame after softstart
    Serial.print(this->thruster_frame[i]);
    Serial.print("\t");
    delay(100);
    
  }
  // free(array);
}

void Thrusters::set_v_forces(int *array){
  this->thruster_frame[4]=array[0];
  this->thruster_frame[5]=array[1];
  Serial.print(this->thruster_frame[4]);
  Serial.print("  ");  
  
  motor_soft_start (this->thruster_frame[4],(motor_controlled_speed + 4) , this->thruster_frame ,(char) 4);
  Serial.print(this->thruster_frame[4]);
  Serial.print("\t");

    Serial.print(this->thruster_frame[5]);
    Serial.print("  ");  

  motor_soft_start (this->thruster_frame[5], (motor_controlled_speed + 5) , this->thruster_frame,(char) 5 );

  Serial.print(this->thruster_frame[5]);
    Serial.print("\t");
  // free(array);
} 

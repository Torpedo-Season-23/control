#include "Thrusters.h"
#include "SoftStart.h"
#include "factors.h"
#include <Arduino.h>

int *Thrusters::get_thruster_frame() {
  return this->thruster_frame;
}

void Thrusters::set_h_forces(int *array) {
  // int16_t maXforceNumber = 0;

  for (int i = 0; i < 4; i++)
    this->thruster_frame[i] = 0;
  for (char i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j)
      this->thruster_frame[i] += this->config_matrix[i][j] * array[j];
    // Serial.print(this->thruster_frame[i]);
    // Serial.print(" ");
    int range = 36;
    if (array[Xforce] != 0 && (array[Yforce] == 0 && array[Moment] == 0))
      range = 64;
    else if (array[Yforce] != 0 && (array[Xforce] == 0 && array[Moment] == 0))
      range = 36;
    else if (array[Moment] != 0 && (array[Xforce] == 0 && array[Yforce] == 0))
      range = 152;
    else if (array[Xforce] != 0 && array[Yforce] != 0 && array[Moment] == 0)
      range = 50;
    else if (array[Xforce] != 0 && array[Moment] != 0 && array[Yforce] == 0)
      range = 108;
    else if (array[Yforce] != 0 && array[Moment] != 0 && array[Xforce] == 0)
      range = 95;
    else if (array[Xforce] != 0 && array[Yforce] != 0 && array[Moment] != 0)
      range = 84;

    // if( ) // temporary:: the back right thruster is inverted
    // this->thruster_frame[i] = map(this->thruster_frame[i], -range, range, 1875, 1125);
    // else
    if ( i == 2 || i == 3)
      this->thruster_frame[i] = map(this->thruster_frame[i], -range, range, 1150, 1850);
    else
      this->thruster_frame[i] = map(this->thruster_frame[i], -range, range, 1850, 1150);

    // Serial.println("thruster orignal");
    // for(int i=0;i<)


  }
  // Serial.println();

  //     maXforceNumber= maXforce(abs(this->thruster_frame[i]),maXforceNumber);
  // 7    //this->thruster_frame[i] = map(this->thruster_frame[i], -36, 36, 1100, 1900);
  //     //print frame after softstart
  //     // delay(100);
  //   }
  //   if(!maXforceNumber)this->speed= 0;
  //     //Serial.println("Zeros");
  //   for (int i = 0; i < 4; i++)
  //     this->thruster_frame[i] = map(this->thruster_frame[i], -1*maXforceNumber, maXforceNumber, 1500-this->speed, 1500+this->speed);
}

void Thrusters::set_v_forces(int *array) {
   if(array[0] ==1500){
    this->thruster_frame[4]= 1500;
    this->thruster_frame[5]= 1500;
    return;
    };
  if (array[0] > 1500 && array[0] < 1750)
    this->thruster_frame[4] = 1750;
  else if(array[0] < 1500 & array[0] > 1250)
    this->thruster_frame[4]= 1250;
  else
    this->thruster_frame[4] = array[0];

  if (array[1] > 1500 && array[1] < 1750)
    this->thruster_frame[5] = 1750;
  else if(array[1] < 1500 & array[1] > 1250)
    this->thruster_frame[5]= 1250;
  else
    this->thruster_frame[5] = array[1];   
  
  Serial.print(this->thruster_frame[4]);
  Serial.print("  ");

  // Serial.print(this->thruster_frame[4]);
  // Serial.print("\t");

  Serial.print(this->thruster_frame[5]);
  Serial.print("  ");

  // Serial.print(this->thruster_frame[5]);
  //   Serial.print("\t");
  // free(array);
}

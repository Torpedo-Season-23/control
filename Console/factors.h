#ifndef FACTORS_H
#define FACTORS_H
#include "config.h"

class Factor{

  float factors[DIRECTIONS][SPEEDS_NUMBER][MOTORS_NUMBER] = {0};
  
  public:

//   #define FRONT_LEFT  5//1
// #define FRONT_RIGHT 2 //2 *
// #define BACKWARD_LEFT 3 //3*//ma3kos
// #define BACKWARD_RIGHT 1 //5*

// #define UPPER_BACK 0 //0*
// #define UPPER_FRONT 4 //4*

// //factors 
// #define FORWARD 0
// #define BACKWARD 1
// #define RIGHT 2
// #define LEFT 3
// #define OTHER -1

// #define LOW_SPEED 0 
// #define NORMAL_SPEED 1
// #define HIGH_SPEED 2


  Factor(){
    for(int dir= 0;dir<4;dir++)
      for(int spe= 0;spe<3;spe++)
        for(int i= 0;i<6;i++)
          factors[dir][spe][i]=1;

    //forward low
    this->factors[FORWARD][LOW_SPEED][FRONT_LEFT] = 1;
    this->factors[FORWARD][LOW_SPEED][FRONT_RIGHT] = 0.85;
    this->factors[FORWARD][LOW_SPEED][BACKWARD_LEFT] = 1;
    this->factors[FORWARD][LOW_SPEED][BACKWARD_RIGHT] = 1;
    //forward normal 
    this->factors[FORWARD][NORMAL_SPEED][FRONT_LEFT] = 1;
    this->factors[FORWARD][NORMAL_SPEED][FRONT_RIGHT] = 0.85;
    this->factors[FORWARD][NORMAL_SPEED][BACKWARD_LEFT] = 1;
    this->factors[FORWARD][NORMAL_SPEED][BACKWARD_RIGHT] = 1;
    //forward High
    this->factors[FORWARD][HIGH_SPEED][FRONT_LEFT] = 1;
    this->factors[FORWARD][HIGH_SPEED][FRONT_RIGHT] = 1;
    this->factors[FORWARD][HIGH_SPEED][BACKWARD_LEFT] = 1;
    this->factors[FORWARD][HIGH_SPEED][BACKWARD_RIGHT] = 1;


    //backward Low
    this->factors[BACKWARD][LOW_SPEED][FRONT_LEFT] = 1;
    this->factors[BACKWARD][LOW_SPEED][FRONT_RIGHT] = 1;
    this->factors[BACKWARD][LOW_SPEED][BACKWARD_LEFT] = 1;
    this->factors[BACKWARD][LOW_SPEED][BACKWARD_RIGHT] = 1;
    //backward Normal
    this->factors[BACKWARD][NORMAL_SPEED][FRONT_LEFT] = 1;
    this->factors[BACKWARD][NORMAL_SPEED][FRONT_RIGHT] = 1;
    this->factors[BACKWARD][NORMAL_SPEED][BACKWARD_LEFT] = 1;
    this->factors[BACKWARD][NORMAL_SPEED][BACKWARD_RIGHT] = 1;
    //backward High
    this->factors[BACKWARD][HIGH_SPEED][FRONT_LEFT] = 1;
    this->factors[BACKWARD][HIGH_SPEED][FRONT_RIGHT] = 1;
    this->factors[BACKWARD][HIGH_SPEED][BACKWARD_LEFT] = 1;
    this->factors[BACKWARD][HIGH_SPEED][BACKWARD_RIGHT] = 1;


     //Right Low
    this->factors[RIGHT][LOW_SPEED][FRONT_LEFT] = 0.92;
    this->factors[RIGHT][LOW_SPEED][FRONT_RIGHT] = 1;
    this->factors[RIGHT][LOW_SPEED][BACKWARD_LEFT] = 1;
    this->factors[RIGHT][LOW_SPEED][BACKWARD_RIGHT] = 0.92;
    //Right Normal
    this->factors[RIGHT][NORMAL_SPEED][FRONT_LEFT] = .95;
    this->factors[RIGHT][NORMAL_SPEED][FRONT_RIGHT] = 1;
    this->factors[RIGHT][NORMAL_SPEED][BACKWARD_LEFT] = 1;
    this->factors[RIGHT][NORMAL_SPEED][BACKWARD_RIGHT] = .95;
    //Right High
    this->factors[RIGHT][HIGH_SPEED][FRONT_LEFT] = 1;
    this->factors[RIGHT][HIGH_SPEED][FRONT_RIGHT] = 1;
    this->factors[RIGHT][HIGH_SPEED][BACKWARD_LEFT] = 1;
    this->factors[RIGHT][HIGH_SPEED][BACKWARD_RIGHT] = 1;

    
    //left
     //left Low
    this->factors[LEFT][LOW_SPEED][FRONT_LEFT] = .95;
    this->factors[LEFT][LOW_SPEED][FRONT_RIGHT] = .9;
    this->factors[LEFT][LOW_SPEED][BACKWARD_LEFT] = 1;
    this->factors[LEFT][LOW_SPEED][BACKWARD_RIGHT] = 1;

    //left Normal
    this->factors[LEFT][NORMAL_SPEED][FRONT_LEFT] = .8;
    this->factors[LEFT][NORMAL_SPEED][FRONT_RIGHT] = .8;
    this->factors[LEFT][NORMAL_SPEED][BACKWARD_LEFT] = 1;
    this->factors[LEFT][NORMAL_SPEED][BACKWARD_RIGHT] = 1;
 
    //left High
    this->factors[LEFT][HIGH_SPEED][FRONT_LEFT] = 1;
    this->factors[LEFT][HIGH_SPEED][FRONT_RIGHT] = 1;
    this->factors[LEFT][HIGH_SPEED][BACKWARD_LEFT] = 1;
    this->factors[LEFT][HIGH_SPEED][BACKWARD_RIGHT] = 1;
  
  }
  void getFactor(int8_t dir ,int speed, uint16_t *thrusterFrame){
    
     if (dir == OTHER)
      return;

    uint8_t speedIndex = 0 ; 
    if(speed == 100){
      speedIndex = 0;
      Serial.print("Low ||");
    }
    if(speed == 250){
      speedIndex = 1;
      Serial.print("Normal ||");
    }
    if(speed == 400){
      speedIndex = 2;
      Serial.print("HIgh ||");
    } 
    Serial.println("");
   
    for(int i= 0;i<6;i++){
            
       int sp= ((int16_t)thrusterFrame[i]-1500) * this->factors[dir][speedIndex][i];
      thrusterFrame[i]= 1500+sp;
    }
  }
};

#endif
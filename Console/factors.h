#ifndef FACTORS_H
#define FACTORS_H
// #include "config.h"
#define FRONT_LEFT 0      //1           2
#define FRONT_RIGHT 3     //2 * mmmmmmmm  0
#define BACKWARD_LEFT 1   //4*         4
#define BACKWARD_RIGHT 2  //5 mmmmm  1



#define FRONT_LEFT1 0      //1           2
#define FRONT_RIGHT1 2     //2 * mmmmmmmm  0
#define BACKWARD_LEFT1 1   //4*         4
#define BACKWARD_RIGHT1 3  //5 mmmmm  1

class Factor {

  float factors[DIRECTIONS][SPEEDS_NUMBER][MOTORS_NUMBER] = { 0 };

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


  Factor() {
    for (int dir = 0; dir < 4; dir++)
      for (int spe = 0; spe < 3; spe++)
        for (int i = 0; i < 6; i++)
          factors[dir][spe][i] = 1;

    //forward low
    this->factors[FORWARD][LOW_SPEED][FRONT_LEFT] = 0.98;
    this->factors[FORWARD][LOW_SPEED][FRONT_RIGHT] = 1;
    this->factors[FORWARD][LOW_SPEED][BACKWARD_LEFT] = -0.98;
    this->factors[FORWARD][LOW_SPEED][BACKWARD_RIGHT] = 0.9;

    //     #define FRONT_LEFT 0  //1           2
    // #define FRONT_RIGHT 3  //2 * mmmmmmmm  0
    // #define BACKWARD_LEFT 1 //4*         4
    // #define BACKWARD_RIGHT 2 //5 mmmmm  1

    //forward normal
    this->factors[FORWARD][NORMAL_SPEED][FRONT_LEFT] = 0.82;
    this->factors[FORWARD][NORMAL_SPEED][FRONT_RIGHT] = 0.85;
    this->factors[FORWARD][NORMAL_SPEED][BACKWARD_LEFT] = -0.85;
    this->factors[FORWARD][NORMAL_SPEED][BACKWARD_RIGHT] = 1;

    //forward High
    this->factors[FORWARD][HIGH_SPEED][FRONT_LEFT] = 0.76;
    this->factors[FORWARD][HIGH_SPEED][FRONT_RIGHT] = 1;
    this->factors[FORWARD][HIGH_SPEED][BACKWARD_LEFT] = -0.74;
    this->factors[FORWARD][HIGH_SPEED][BACKWARD_RIGHT] = 1;


    //backward Low
    this->factors[BACKWARD][LOW_SPEED][FRONT_LEFT] = 0.99;
    this->factors[BACKWARD][LOW_SPEED][FRONT_RIGHT] = 0.9;
    this->factors[BACKWARD][LOW_SPEED][BACKWARD_LEFT] = -0.99;
    this->factors[BACKWARD][LOW_SPEED][BACKWARD_RIGHT] = 0.87;

    //backward Normal
    this->factors[BACKWARD][NORMAL_SPEED][FRONT_LEFT] = 0.94;
    this->factors[BACKWARD][NORMAL_SPEED][FRONT_RIGHT] = 0.7;
    this->factors[BACKWARD][NORMAL_SPEED][BACKWARD_LEFT] = -0.91;
    this->factors[BACKWARD][NORMAL_SPEED][BACKWARD_RIGHT] = 0.95;
    // fl bl br fr
    //     #define FRONT_LEFT 0  //1           2
    // #define FRONT_RIGHT 3  //2 * mmmmmmmm  0
    // #define BACKWARD_LEFT 1 //4*         4
    // #define BACKWARD_RIGHT 2 //5 mmmmm  1


    //backward High
    this->factors[BACKWARD][HIGH_SPEED][FRONT_LEFT1] = 0.98;
    this->factors[BACKWARD][HIGH_SPEED][FRONT_RIGHT1] = 0.93;
    this->factors[BACKWARD][HIGH_SPEED][BACKWARD_LEFT1] = -0.98;
    this->factors[BACKWARD][HIGH_SPEED][BACKWARD_RIGHT1] = 1;


    // #define FRONT_LEFT 0
    // #define FRONT_RIGHT 2
    // #define BACKWARD_LEFT 1
    // #define BACKWARD_RIGHT 3
    //Right Low
    this->factors[RIGHT][LOW_SPEED][FRONT_LEFT1] = -0.82;
    this->factors[RIGHT][LOW_SPEED][FRONT_RIGHT1] = -0.9;
    this->factors[RIGHT][LOW_SPEED][BACKWARD_LEFT1] = 0.98;
    this->factors[RIGHT][LOW_SPEED][BACKWARD_RIGHT1] = -0.99;

    //Right Normal
    this->factors[RIGHT][NORMAL_SPEED][FRONT_LEFT1] = -0.7;
    this->factors[RIGHT][NORMAL_SPEED][FRONT_RIGHT1] = -0.83;
    this->factors[RIGHT][NORMAL_SPEED][BACKWARD_LEFT1] = 0.98;
    this->factors[RIGHT][NORMAL_SPEED][BACKWARD_RIGHT1] = -0.7;

    //Right High
    this->factors[RIGHT][HIGH_SPEED][FRONT_LEFT1] = -0.85;
    this->factors[RIGHT][HIGH_SPEED][FRONT_RIGHT1] = -0.8;
    this->factors[RIGHT][HIGH_SPEED][BACKWARD_LEFT1] = 0.95;
    this->factors[RIGHT][HIGH_SPEED][BACKWARD_RIGHT1] = -0.95;


    // #define FRONT_LEFT 0
    // #define FRONT_RIGHT 2
    // #define BACKWARD_LEFT 1
    // #define BACKWARD_RIGHT 3
    //left
    //left Low
    this->factors[LEFT][LOW_SPEED][FRONT_LEFT1] = -0.98;
    this->factors[LEFT][LOW_SPEED][FRONT_RIGHT1] = -0.9;
    this->factors[LEFT][LOW_SPEED][BACKWARD_LEFT1] = 0.93;
    this->factors[LEFT][LOW_SPEED][BACKWARD_RIGHT1] = -0.95;
    //left Normal
    this->factors[LEFT][NORMAL_SPEED][FRONT_LEFT1] = -1;
    this->factors[LEFT][NORMAL_SPEED][FRONT_RIGHT1] = -0.88;
    this->factors[LEFT][NORMAL_SPEED][BACKWARD_LEFT1] = 0.76;
    this->factors[LEFT][NORMAL_SPEED][BACKWARD_RIGHT1] = -0.81;

    //left High
    this->factors[LEFT][HIGH_SPEED][FRONT_LEFT1] = -1;
    this->factors[LEFT][HIGH_SPEED][FRONT_RIGHT1] = 1;
    this->factors[LEFT][HIGH_SPEED][BACKWARD_LEFT1] = 1;
    this->factors[LEFT][HIGH_SPEED][BACKWARD_RIGHT1] = 1;
  }


  void setFactors(int8_t dir, int speed, float *fact) {
    if (dir < 0)
      return;

    uint8_t speedIndex = 0;
    if (speed == 100) {
      speedIndex = 0;
      // Serial.print("Low ||");
    }
    if (speed == 250) {
      speedIndex = 1;
      // Serial.print("Normal ||");
    }
    if (speed == 400) {
      speedIndex = 2;
      // Serial.print("HIgh ||");
    }
    for (int i = 0; i < 4; i++) {
      this->factors[dir][speedIndex][i] = fact[i];
    }
  }
  void apply(int8_t dir, int speed, uint16_t *thrusterFrame);
  void getFactor(int8_t dir, int speed, uint16_t *thrusterFrame) {

    if (dir < 0)
      return;

    uint8_t speedIndex = 0;
    if (speed == 100) {
      speedIndex = 0;
      // Serial.print("Low ||");
    }
    if (speed == 250) {
      speedIndex = 1;
      // Serial.print("Normal ||");
    }
    if (speed == 400) {
      speedIndex = 2;
      // Serial.print("HIgh ||");
    }
    // Serial.println("");

    // Serial.print("dir : ");
    // Serial.print(dir);
    // Serial.print("speed : ");
    // Serial.print(speedIndex);
    // Serial.print("factor : ");
    for (int i = 0; i < 6; i++) {
      // Serial.print(this->factors[dir][speedIndex][i]);
      // Serial.print(" ");

      int sp = ((int16_t)thrusterFrame[i] - 1500) * this->factors[dir][speedIndex][i];
      thrusterFrame[i] = 1500 + sp;
    }
    // Serial.println();
  }
};

#endif

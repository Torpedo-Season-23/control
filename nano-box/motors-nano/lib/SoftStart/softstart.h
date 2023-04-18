#ifndef _SOFT_START_H_
#define _SOFT_START_H_

#include "../Servo/Servo.h"
#include "../code/config.h"
extern float exponent;  // need to be defined at ".ino" file

#define TIME_STEP 80.0  // time difference to use soft start

#define EXPONENT exponent     // affect rising rate for the motor
#define STEP_SPEED 30         // maximum speed difference to not use soft start
#define MOT_MAX_SPEED 1900    // motors max speed
#define MOT_MIN_SPEED 1100    // motors max speed in opposite direction
#define MOT_ZERO_SPEED 1500   // motors stop speed
#define MOT_SPEED_DIFF 400.0  // difference between any max speed and the stop speed (1900-1500)
// calculate
#define TIME_STEP_RETURN_UP (-log(-((*motor_controlled_speed) - MOT_MAX_SPEED) / MOT_SPEED_DIFF)) * 1000 / (TIME_STEP * EXPONENT)
#define TIME_STEP_RETURN_DOWN (-log(((*motor_controlled_speed) - MOT_MIN_SPEED) / MOT_SPEED_DIFF)) * 1000 / (TIME_STEP * EXPONENT)
// speed change values for speeds higher than 1500
#define SOFT_START_UP (MOT_MAX_SPEED - (MOT_SPEED_DIFF * exp(-EXPONENT * TIME_STEP * speed_counter[i] / 1000.0)))
// speed change values for speeds Lower than 1500
#define SOFT_START_DOWN (MOT_MIN_SPEED + (MOT_SPEED_DIFF * exp(-EXPONENT * TIME_STEP * speed_counter[i] / 1000.0)))
#define SOFT_START_UP 0
#define SOFT_START_DOWN 1

class Soft {
 public:
  static void softStartInitial();                                                                                                        // to be called in setup(initiate time values)
  static void softStart(char type, uint16_t motor_speed, uint16_t *motor_controlled_speed, MOTOR_ORIENTATION i);                         // contorl soft start stages(speed changes)
  static void motorSoftStart(Servo *motor_num, uint16_t motor_speed, uint16_t *motor_controlled_speed, MOTOR_ORIENTATION i, float EXP);  // control speed coming form console
};

#ifndef _SOFT_START_CPP_
#include "softstart.cpp"
#endif

#endif
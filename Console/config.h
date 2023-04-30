#ifndef CONFIG_H
#define CONFIG_H


/*---------------Speeds---------------*/
#define SPEEDS_NUMBER 3
#define LOW_SPEED_VALUE 42
#define NORMAL_SPEED_VALUE 85
#define HIGH_SPEED_VALUE 128

/*-----------------communication-----------------*/
#define receivedFrameSize 22  //6 imu, 2 pressure, 8 leakage, 2curr 1temp, 2curr 1 temp respectively
#define sentFrameSize 8       //1 accessories, 1 directions+conv on/off, 6 speeds respectively
#define SENSORS 16
#define IMU 3
#define PRESSURE 1
#define CURRENT 2
#define TEMPERATURE 2
#define LEAKAGE 8
#define THRUSTERS 6
#define ACCESSORIES 8

//soft Start
#define MOTORS_NUMBER 6
#define MOTOR_STATIC_SPEED 1500
#define MOTOR_HIGHEST_SPEED 1900
#define MOTOR_LOWEST_SPEED 1100
#define TIME_STEP 500
#define INCREAMENT_FACTOR 2
#define log2(a) (log(a) / log(2))
/*----------Outer Thruster Frame*/
// typedef enum FrameMotorIndices {
//   FRONT_LEFT = 0,
//   UPPER_BACK,
//   FRONT_RIGHT,
//   BACKWARD_LEFT,
//   BACKWARD_RIGHT,
//   UPPER_FRONT,
//   LAST
// } FrameMotorIndices;



//BACK LEFT : 0
//BACK RIGHT :2
//FRONT RIGHT :3



#define FRONT_LEFT  5//1
#define FRONT_RIGHT 2 //2 *
#define BACKWARD_LEFT 3 //3*//ma3kos
#define BACKWARD_RIGHT 1 //5*

#define UPPER_BACK 0 //0*
#define UPPER_FRONT 4 //4*

#endif
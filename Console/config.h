#ifndef CONFIG_H
#define CONFIG_H


/*---------------Speeds---------------*/
#define SPEEDS_NUMBER 3
#define LOW_SPEED_VALUE_mom 30
#define LOW_SPEED_VALUE 42
#define NORMAL_SPEED_VALUE 85
#define HIGH_SPEED_VALUE 128

/*-----------------communication-----------------*/
#define receivedFrameSize 10  //6 imu, 2 pressure, 8 leakage, 2curr 1temp, 2curr 1 temp respectively
#define sentFrameSize 13       //1 accessories, 1 directions+conv on/off, 6 speeds respectively
#define SENSORS 4
#define IMU 3
#define PRESSURE 1
#define TEMPRATURE 1
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

//BACK LEFT : 0
//BACK RIGHT :2
//FRONT RIGHT :3




#define FRONT_LEFT 0  //1           2
#define FRONT_RIGHT 3  //2 * mmmmmmmm  0
#define BACKWARD_LEFT 1 //4*         4
#define BACKWARD_RIGHT 2 //5 mmmmm  1


#define UPPER_FRONT 4 //3*       3
#define UPPER_BACK 5 //0*          5



//factors 
#define FORWARD 0
#define BACKWARD 1
#define RIGHT 2
#define LEFT 3
#define STOP -1
#define UP -2
#define DOWN -3
#define M_LEFT -4
#define M_RIGHT -5


#define DIRECTIONS 4
//speeds for factors
#define LOW_SPEED 0 
#define NORMAL_SPEED 1
#define HIGH_SPEED 2




#endif

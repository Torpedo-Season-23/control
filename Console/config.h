#ifndef CONFIG_H
#define CONFIG_H


/*---------------Speeds---------------*/
#define SPEEDS_NUMBER 3
#define LOW_SPEED_VALUE 42
#define NORMAL_SPEED_VALUE 85
#define HIGH_SPEED_VALUE 128

/*-----------------communication-----------------*/
//
#define receivedFrameSize 22  //in bytes, IMU: 3*2, Pressure: 1*2, Converters: 2*3, Leakage: 8 respectively
#define sentFrameSize 8      //in bytes, Accessories: 1, Converters ON/OFF + directions: 1, Speeds: 6 respectively (will be changed if softstart is added)

// from BOX to CONSOLE
#define SENSORS 12
#define IMU 3
#define PRESSURE 1
#define LEAKAGE 8

#define CURRENT 2 //from 2 converters
#define TEMPERATURE 2 //from 2 converters
#define TOTAL 16 //Total readings

// from CONSOLE to BOX
#define THRUSTERS 6
#define ACCESSORIES 8 

//soft Start
#define MOTORS_NUMBER 6
#define MOTOR_STATIC_SPEED 1500
#define MOTOR_HIGHEST_SPEED 1900
#define MOTOR_LOWEST_SPEED 1100
#define TIME_STEP 500
#define INCREAMENT_FACTOR 3 
#define log2(a) (log(a)/log(2))


#endif

#ifndef CONFIG_H
#define CONFIG_H


/*---------------Speeds---------------*/
#define SPEEDS_NUMBER 3
#define LOW_SPEED_VALUE 42
#define NORMAL_SPEED_VALUE 85
#define HIGH_SPEED_VALUE 128

/*-----------------communication-----------------*/
#define receivedFrameSize 11  //11 bytes, IMU: 3*2bytes, Pressure: 1*2bytes, Current: 2*1bytes, Leakage: 1byte respectively
#define sentFrameSize 8      //8 bytes, Thrusters: 7bytes, Accessories: 1 byte respectively (will be changed if softstart is added)
#define SENSORS 7
#define IMU 3
#define PRESSURE 1
#define CURRENT 2
#define LEAKAGE 1
#define THRUSTERS 6
#define ACCESSORIES 8  //will be modified (1 byte anyways)

#endif
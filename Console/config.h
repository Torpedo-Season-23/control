#ifndef CONFIG_H
#define CONFIG_H


/*---------------Speeds------------------*/
#define SPEEDS_NUMBER 3
#define LOW_SPEED_VALUE 42
#define NORMAL_SPEED_VALUE 85
#define HIGH_SPEED_VALUE 128

/*-----------------communication----------------------*/
#define receivedFrameSize 10  //10 bytes, IMU: 3*2bytes, Pressure: 1*2bytes, Current: 2*1bytes respectively
#define sentFrameSize 13      //13 bytes, Thrusters: 6*2bytes, Accessories: 1 byte respectively (will be changed if softstart is added)
#define SENSORS 6
#define IMU 3
#define CURRENT 2
#define PRESSURE 1
#define THRUSTERS 6
#define ACCESSORIES 4  //will be modified (1 byte anyways)

#endif

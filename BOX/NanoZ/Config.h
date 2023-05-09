#ifndef OUT_H
#define OUT_H
#include <Arduino.h>


#define MOTORS_COUNT 6
#define TOOLS_COUNT 8

//uart frame size
#define UART_Z_FRAME_SIZE 10  // (1 gaurd | 1 Accessories | 1 Directions | 6 Motor | 2 Braking | 1 gaurd )(bytes)
#define ACTUAL_DATA 8         // ( 1 Accessories | 1 directions | 6 Motor | 2 Braking )(bytes)

//Nanoz data Indices
#define MOTORS_SPEEDS_INDEX 2
#define DIRECTIONS_BYTE_INDEX 1
#define ACC_BYTE_INDEX 0

//uart pins
#define RX_Z 7
#define TX_Z 8

//Motors speeds
#define MOT_ZERO_SPEED 1500
#define MOT_MAX_SPEED 1900
#define MOT_MIN_SPEED 1100


//debuging
// #define THRUSTERS_PRINT_ON
// #define ACC_PRINT_ON
// #define UART_PRINT_ON

#endif

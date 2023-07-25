#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>


#define MOTORS_COUNT 6
#define TOOLS_COUNT 8

#define ACTUAL_DATA 13        // (1 Accessories | 6 * 2 Motor )(bytes)

//Nanoz data Indices
#define MOTORS_SPEEDS_INDEX 1
// #define DIRECTIONS_BYTE_INDEX 1
#define ACC_BYTE_INDEX 0

//Motors speeds
#define MOT_ZERO_SPEED 1500
#define MOT_MAX_SPEED 1900
#define MOT_MIN_SPEED 1100


//Communication
#define BOX_PORT 8000
#define CONSOLE_PORT 7000

/*--------UDP--------*/
#define UDP_REC_FRAME 13  // 1 Accessories,  6 thrusters speeds * 2 bytes
#define UDP_SEND_FRAME 8  // for communication test

/*-------MUX-------*/
#define MUX_SIG_PIN 0
#define MUX_CH1_PIN 0
#define MUX_CH2_PIN 0
#define MUX_CH3_PIN 0
#define MUX_CHANALES 3


//debuging
// #define THRUSTERS_PRINT_ON
// #define ACC_PRINT_ON


/* LEAKAGE */
#define DHTTYPE DHT11
#define SENSORS_NUM 8
#define DHTPIN 2

/* PRESSURE */
#define MCLK_PIN 10
#define MISO_PIN 12
#define MOSI_PIN 11
#define SCLK_PIN 13




#endif

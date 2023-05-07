#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>

// GLOBAL
#define BAUD_RATE 115200
#define SENSORS_INTERRUPT_PIN 2

// SOFTWARE SERIAL
#define SENSORS_SOFTWARE_SERIAL_RX 8
#define SENSORS_SOFTWARE_SERIAL_TX 9
#define UART_FRAME_RECEIVED_SIZE 14
#define UART_FRAME_SENT_SIZE 14
#define RELIABLE_START_FRAME '('
#define RELIABLE_END_FRAME ')'

// PRESSURE SENSOR
#define DEBUG_PRESSURE 1
#define AIR_PRESSURE 1013
#define PRESSURE_MCLK 10         // 10 for nano - 9 for mega
#define PRESSURE_MISO 7          // 7 for nano - 12 for mega
#define PRESSURE_MOSI 8          // 8 for nano - 11 for mega
#define PRESSURE_SCLK 9          // 9 for nano - 13 for mega
#define D1_SEQUENCE 0x0F40       // pressure measurement sequence
#define D2_SEQUENCE 0x0F20       // temperature measurement sequence
#define WORD1_SEQUENCE 0x1D50    // word1 sequence
#define WORD2_SEQUENCE 0x1D60    // word2 sequence
#define WORD3_SEQUENCE 0x1D90    // word3 sequence
#define WORD4_SEQUENCE 0x1DA0    // word4 sequence
#define RESET_SEQUENCE 0x155540  // reset sequence
#define CONVERSION_DELAY_MS 35
#define COMM_FREQUENCY 500000

// MPU6050 SENSOR
#define DEBUG_MPU 1

// SENSORS
#define SENSORS_FRAME_SIZE 8
#define PRESSURE_FRAME_SIZE 2
#define MPU_FRAME_SIZE 6

#endif
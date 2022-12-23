#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>

// TODO: PUT RIGHT PINS AND VALUES

// GLOBAL
#define BAUD_RATE 115200

enum DIRECTION {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    MOMENT_LEFT,
    MOMENT_RIGHT,
    UP,
    DOWN,
    STOP,
    GENERIC,
};

// ROV
#define SENSOR_COUNT 6
#define SENSORS_DATA_SIZE 10

// DEBUG FOR PRINTING SENSORS
#define DEBUG_SENSORS 1

enum SENSOR_TYPE {
    PRESSURE,
    IMU,
    CURRENT_SENSOR_FRONT_LEFT,
    CURRENT_SENSOR_FRONT_RIGHT,
    CURRENT_SENSOR_BACK_LEFT,
    CURRENT_SENSOR_BACK_RIGHT,
    NO_SENSOR,
};

// IMU SENSOR
#define IMU_ADDRESS 0x68
#define IMU_TIMEOUT 10000UL
#define IMU_WRITE_REG_INIT 0x6B
#define IMU_WRITE_REG_UPDATE 0x3B
#define IMU_REQUEST 14
#define ZERO_REG 0x00
#define ACCELARATION_OFFSET 100
#define ACCELARATION_NORMALIZATION 195

// PRESSURE SENSOR
#define PRESSURE_MCLK 13
#define PRESSURE_MISO 12
#define PRESSURE_MOSI 11
#define PRESSURE_SCLK 10
#define D1_SEQUENCE 0x0F40       // pressure measurement sequence
#define D2_SEQUENCE 0x0F20       // temperature measurement sequence
#define WORD1_SEQUENCE 0x1D50    // word1 sequence
#define WORD2_SEQUENCE 0x1D60    // word2 sequence
#define WORD3_SEQUENCE 0x1D90    // word3 sequence
#define WORD4_SEQUENCE 0x1DA0    // word4 sequence
#define RESET_SEQUENCE 0x155540  // reset sequence
#define CONVERSION_DELAY_MS 35
#define COMM_FREQUENCY 500000

// CURRENT SENSOR
#define VIN A1
#define VCC 5.0
#define CURRENT_SENSOR_FRONT_LEFT_PIN A2
#define CURRENT_SENSOR_FRONT_RIGHT_PIN A3
#define CURRENT_SENSOR_BACK_LEFT_PIN A4
#define CURRENT_SENSOR_BACK_RIGHT_PIN A5

// ACCESSORIES
#define ACCESSORIES_COUNT 8
#define ACCESSORIES_INDEX 0
#define RIGHT_GRIPPER_PIN A0
#define LEFT_GRIPPER_PIN A2
#define LIGHTS_PIN A4
#define IMU_TOGGLE_PIN A12
#define PRESSURE_TOGGLE_PIN A14
#define ACCESORIES_EMPTY1_PIN A6
#define ACCESORIES_EMPTY2_PIN A8
#define ACCESORIES_EMPTY3_PIN A10

enum ACCESSORIES_TYPE {
    RIGHT_GRIPPER,
    LEFT_GRIPPER,
    LIGHTS,
    IMU_TOGGLE,
    PRESSURE_TOGGLE,
    ACCESORIES_EMPTY1,
    ACCESORIES_EMPTY2,
    ACCESORIES_EMPTY3,
};

// MOTOR

// DEBUG FOR MOTION
#define DEBUG_MOTION 1

enum MOTOR_ORIENTATION {
    HORIZONTAL_FRONT_LEFT,
    HORIZONTAL_FRONT_RIGHT,
    HORIZONTAL_BACK_LEFT,
    HORIZONTAL_BACK_RIGHT,
    VERTICAL_FRONT,
    VERTICAL_BACK,
    VERTICAL_LEFT,
    VERTICAL_RIGHT
};

#define MOTOR_COUNT 8
#define SPEED_INDEX_START 1
#define EXPONENT_INDEX_START 17
#define EXPONENT_INITAL 2.0
#define DIRECTION_INDEX 26
#define HORIZONTAL_FRONT_LEFT_PIN 2
#define HORIZONTAL_FRONT_RIGHT_PIN 3
#define HORIZONTAL_BACK_LEFT_PIN 4
#define HORIZONTAL_BACK_RIGHT_PIN 5
#define VERTICAL_FRONT_PIN 6
#define VERTICAL_BACK_PIN 7
#define VERTICAL_LEFT_PIN 8
#define VERTICAL_RIGHT_PIN 9
#define STOP_SPEED 1500
#define MAX_INTERVAL 400

// ETHERNET
#define MAC_COUNT 6
#define IP_COUNT 4
#define DNS_COUNT 4
#define GATEWAY_COUNT 4
#define SUBNET_COUNT 4
#define ETHERNET_BOX_MAC_0 0xDE
#define ETHERNET_BOX_MAC_1 0xAD
#define ETHERNET_BOX_MAC_2 0xBE
#define ETHERNET_BOX_MAC_3 0xEF
#define ETHERNET_BOX_MAC_4 0xFE
#define ETHERNET_BOX_MAC_5 0xED
#define IP_0 192
#define IP_1 168
#define IP_2 1
#define BOX_IP_3 7
#define CONSOLE_IP_3 9
#define BOX_PORT 8000
#define CONSOLE_PORT 7000
#define FRAME_RECIEVED_SIZE 18
#define FRAME_SENT_SIZE 10

#endif
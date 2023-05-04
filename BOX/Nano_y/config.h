#ifndef CONFIG_H
#define CONFIG_H


/* PRESSURE */
#define MCLK_PIN 10
#define MISO_PIN 12
#define MOSI_PIN 11
#define SCLK_PIN 13

// /* UART */
#define Imu_Angles_Index 0
#define PRESSURE_index Imu_Angles_Index + 3 * 2
#define FRAME_SIZE 8 

#define RX_Y 8
#define TX_Y 9

#endif

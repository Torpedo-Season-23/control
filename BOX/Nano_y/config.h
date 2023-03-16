#ifndef CONFIG_H
#define CONFIG_H

/* LEAKAGE */
#define DHTTYPE DHT11  
#define SENSORS_NUM 8
#define DHTPIN 2 

/* PRESSURE */
#define MCLK_PIN 10
#define MISO_PIN 12
#define MOSI_PIN 11
#define SCLK_PIN 13

/* UART */
#define Imu_Angles_Index 0
#define PRESSURE_index Imu_Angles_Index + 3 * 2




#endif

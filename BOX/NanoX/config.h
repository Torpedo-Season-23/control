#ifndef CONFIG_H
#define CONFIG_H

/*from BOX to CONSOLE*/
#define UDP_REC_FRAME 8 //(bytes): 1 Accessories, 1 directions + converters on/off, 6 thrusters speeds "respectively"
#define UDP_SEND_FRAME 22 //(bytes): 6 IMU angles, 2 pressure, 8 leakage, 3*2 converters(2 bytes for current, 1 for temperature) "respectively"

/*from SENSORS NANO to ETHERNET NANO*/
#define UART_y_FRAME_SIZE 16
#define RX_Y 2
#define TX_Y 4
#define ANGLE_INDEX 0
#define PRESSURE_INDEX ANGLE_INDEX + 3*2
#define LEAKAGE_INDEX PRESSURE_INDEX + 2
#define Converters_INDEx ANGLE_INDEX + 3*2 + 2
#define PIN A0 //Interrupt pin


#endif

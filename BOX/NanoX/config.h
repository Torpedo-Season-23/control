#ifndef CONFIG_H
#define CONFIG_H


#define BOX_PORT 8000
#define CONSOLE_PORT 7000

/*--------UDP--------*/
#define UDP_REC_FRAME 8    //(bytes): 1 Accessories, 1 directions + converters on/off, 6 thrusters speeds "respectively"
#define UDP_SEND_FRAME 16  //22 //(bytes): 6 IMU angles, 2 pressure, 8 leakage, 3*2 converters(2 bytes for current, 1 for temperature) "respectively" CONVERTERS STILL NOT ADDED

/*--------UART--------*/
#define UART_YZ_FRAME_SIZE 8
#define RX_Y 7
#define TX_Y 8
#define ANGLE_INDEX 0
#define PRESSURE_INDEX ANGLE_INDEX + 3 * 2
#define LEAKAGE_INDEX PRESSURE_INDEX + 2
#define Converters_INDEx ANGLE_INDEX + 3 * 2 + 2
#define INTERRUPT_PIN A0  //Interrupt pin


 #define PRINT_ON //Uncomment this line to print debug messages

#endif

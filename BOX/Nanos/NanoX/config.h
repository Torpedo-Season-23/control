#ifndef CONFIG_H
#define CONFIG_H


#define BOX_PORT 8000
#define CONSOLE_PORT 7000

/*--------UDP--------*/
#define UDP_REC_FRAME 13  // 1 Accessories,  6 thrusters speeds * 2 bytes
#define UDP_SEND_FRAME 8  // for communication test

/*--------UART--------*/
// #define UART_YZ_FRAME_SIZE 8
// #define RX_Y 7
// #define TX_Y 8
// #define ANGLE_INDEX 0
// #define PRESSURE_INDEX ANGLE_INDEX + 3 * 2
// #define INTERRUPT_PIN A0  //Interrupt pin


//#define PRINT_ON //Uncomment this line to print debug messages
#endif
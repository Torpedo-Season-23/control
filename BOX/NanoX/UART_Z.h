#ifndef UART_Z_H
#define UART_Z_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#define UART_Z_FRAME_SIZE 15// (( 12 Motor | 1 Accessories ))
#define RX_Z 8
#define TX_Z 9
#define MOTOR_INDEX 0
#define ACCESSORY_INDEX MOTOR_INDEX+6*2

class UART_Z{
    public:
        UART_Z(){};
        void begin();
        void sendFrame(uint8_t* frame);
};
#endif

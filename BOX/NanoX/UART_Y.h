#ifndef UART_Y_H
#define UART_Y_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#define UART_y_FRAME_SIZE 10
#define RX_Y 8
#define TX_Y 9
#define ANGLE_INDEX 0
#define PRESSURE_INDEX ANGLE_INDEX + 3*2


class UART_Y{
    public:
        UART_Y(){};
        void begin();
        void receiveFrame(uint8_t* frame);
        void sendFrame(uint8_t*);
};
#endif
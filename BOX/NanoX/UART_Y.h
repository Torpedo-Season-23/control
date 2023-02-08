#ifndef UART_Y_H
#define UART_Y_H
#include <Arduino.h>
#include <SoftwareSerial.h>
#define UART_y_FRAME_SIZE 14// (( 12 Motor | 1 Accessories ))
#define RX_Y 27
#define TX_Y 26
#define ANGLE_INDEX 2
#define PRESSURE_INDEX ANGLE_INDEX + 3*2

struct sensorsData{
    uint16_t angles[3];
    uint16_t pressure;
};

class UART_Y{
    public:
        UART_Y(){};
        void begin();
        void receiveFrame(struct sensorsData* frame);
};
#endif

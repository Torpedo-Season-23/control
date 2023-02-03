#ifndef UART_TERMINAL_H
#define UART_TERMINAL_H
#include <Arduino.h>
#define RX 35
#define TX 13
#define ANGLE_INDEX 0
#define PRESSURE_INDEX ANGLE_INDEX+3*2

void initializeUART();
void receiveSensorData();
#endif

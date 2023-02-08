#include "UART_Z.h"

SoftwareSerial serial(RX_Z, TX_Z);

void UART_Z::begin(){
    serial.begin(9600);}

void UART_Z::sendFrame(uint8_t* frame){
    frame[0]= '(';
    frame[1]= '(';
    frame[UART_Z_FRAME_SIZE-2]= ')';
    frame[UART_Z_FRAME_SIZE-1]= ')';
    serial.write(frame,UART_Z_FRAME_SIZE);
}

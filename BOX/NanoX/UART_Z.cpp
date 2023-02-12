#include "UART_Z.h"

SoftwareSerial serial(RX_Z, TX_Z);

void UART_Z::begin(){
    serial.begin(19200);}

void UART_Z::sendFrame(uint8_t* frame){
    serial.write('(');
    serial.write(frame,UART_Z_FRAME_SIZE);
    serial.write(')');
}

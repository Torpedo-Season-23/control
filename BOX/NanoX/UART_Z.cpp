#include "UART_Z.h"

SoftwareSerial serial(RX_Z, TX_Z);

void UART_Z::begin(){
    serial.begin(9600);}

void UART_Z::sendFrame(uint8_t* sendingFrame){
  sendingFrame[1]= '(';
  sendingFrame[1+4]= ')';
  serial.print("(hel)");
}

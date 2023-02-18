#include "UART_Z.h"

SoftwareSerial serial(RX_Z, TX_Z);

void UART_Z::begin(){
    serial.begin(9600);}

void UART_Z::sendFrame(uint8_t* sendingFrame){
  long now= millis();
  serial.write('(');
  serial.write(sendingFrame,14);
  serial.write(')');
  //Serial.print("Current Time is : ");
  //Serial.println(millis()-now);
  
}

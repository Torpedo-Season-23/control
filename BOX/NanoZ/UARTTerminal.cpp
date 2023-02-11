#include "UARTTerminal.h"


SoftwareSerial serial(RX_Z, TX_Z);

void Uart_z::startUART(){
    serial.begin(9600); 
  }

void Uart_z::receiveFrame(uint8_t *thrustFarme , uint8_t *toolFrame){
  
  while (serial.available()){
    byte x= serial.read();
    byte y= serial.read();
    uint8_t frame2[ACTUAL_DATA] = {0};

    if(x != '(' && y != '('){
       continue;
    }

    while (!serial.available());
    for(int i = 0 ; i < ACTUAL_DATA ; i++){
      while (!serial.available());
      frame2[i] = serial.read();

    }
    
    while (!serial.available());
    x= serial.read();
    y= serial.read();
  
    if(x != ')' && y != ')'){
       continue;
    }
    
    extractData(frame2 , thrustFarme , toolFrame );
   
  }
 
}



void Uart_z::extractData(uint8_t frame[] , uint8_t * thrustFarme, uint8_t *toolFrame ){
  uint8_t thrust[THRUSTERS_signal_FRAME]= {0};
  uint8_t tool[TOOLS_FRAME] = {0} ;

  for(int i = 0 ; i < THRUSTERS_FRAME ; i++ ){
    
    if(i != 0)
      thrust[(MOTORS_COUNT-1)+i] = frame[i];//loop from 1 to 12 

    //Extract Motors directions byte (the first byte in the frame)
     if(i < MOTORS_COUNT){

      if (frame[0] & 1 == 1) {
          thrust[i] = 255;
        } else {
          thrust[i] = 0;
        }
        frame[0] >>= 1;
    }

    //Extract tools byte (the last byte in the frame)
    if(i < TOOLS_COUNT){

      if (frame[ACTUAL_DATA-1] & 1 == 1) {
          tool[i] = 255;
        } else {
          tool[i] = 0;
        }
        frame[ACTUAL_DATA-1] >>= 1;
    }
  }

  thrustFarme = thrust;
  toolFrame = tool;

}




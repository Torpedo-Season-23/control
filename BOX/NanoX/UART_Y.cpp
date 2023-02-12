#include "UART_Y.h"

SoftwareSerial serialY(RX_Y, TX_Y);

void UART_Y::begin() {
  serialY.begin(9600);
}

void UART_Y::receiveFrame(struct sensorsData* data){
  uint8_t recFrame[UART_y_FRAME_SIZE-2];
  while (1) {
    byte x;
    while (!serialY.available());
    x = serialY.read();
    if (x != '(') continue;
    for(int i= 0;i<UART_y_FRAME_SIZE-2;i++){
      while (!serialY.available());
      recFrame[i] = serialY.read();
    }
    while (!serialY.available());
    x = serialY.read();
    if (x != ')') continue;
    /*for(int i= 0;i<8;i++){
      Serial.print(recFrame[i]);
      Serial.print(" ");
    }
    Serial.println();*/
    uint8_t count= 0;
    for(int i= ANGLE_INDEX;i<3;i+=2){
      data->angles[count]= recFrame[i]<<8 | recFrame[i+1];
      count++;
    }
    data->pressure= recFrame[PRESSURE_INDEX]<<8 | recFrame[PRESSURE_INDEX+1];
    return;
  }
  /*
    while(true){
    while(!serialY.available());
    Serial.println("Received!");
    byte x= serialY.read();
    if (x != '(')
        continue;
    while (!serialY.available());
    x= serialY.read();
    if(x != '(')
        continue;
    uint8_t frame[UART_y_FRAME_SIZE-4];
    for(int i= 0;i<UART_y_FRAME_SIZE-4;i++){
        while (!serialY.available());
        frame[i]= serialY.read();
    }
    while (!serialY.available());
    x= serialY.read();
    if(x!=')')
        continue;
    while (!serialY.available());
    x= serialY.read();
    if(x!=')')
        continue;
    uint8_t count= 0;
    for(int i= ANGLE_INDEX;i<6;i+=2){
        data->angles[count]= frame[i]<<8 | frame[i+1];
        count++;
    }
    data->pressure= frame[PRESSURE_INDEX]<<8 | frame[PRESSURE_INDEX+1];
    return;
    }*/
}

void UART_Y::sendFrame(uint8_t* sendingFrame) {
  //uint8_t sendingFrame[] = {'(', 'a', 'b', 'c', 'd', 'e', 'f', 'e', ')'};
  //serialY.print("(abcdefg)");
  //Serial.println("Sending..");
  sendingFrame[1]= '(';
  sendingFrame[1+4]= ')';
  serialY.write(sendingFrame+1,5);
}

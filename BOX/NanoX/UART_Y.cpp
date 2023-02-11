#include "UART_Y.h"

SoftwareSerial serialY(RX_Y, TX_Y);

void UART_Y::begin() {
  serialY.begin(9600);
}

void UART_Y::receiveFrame(struct sensorsData* data) {
  Serial.print("Waiting to receive: ");
  Serial.println(serialY.available());
  while (1) {
    byte x;
    while (!serialY.available());
    x = serialY.read();
    if (x != '(') continue;
    while (!serialY.available());
    x = serialY.read();
    if (x != '(') continue;
    for (int i = 0; i < 7; i++) {
      while (!serialY.available());
      Serial.print((char)serialY.read());
    }
    while (!serialY.available());
    x = serialY.read();
    if (x != ')') continue;
    
    while (!serialY.available());
    x = serialY.read();
    if (x != ')') continue;
    
    Serial.println();
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

void UART_Y::sendFrame() {
  uint8_t sendingFrame[] = {'(', 'a', 'b', 'c', 'd', 'e', 'f', 'e', ')'};
  serialY.print("(abcdefg)");
  Serial.println("Sending..");
}

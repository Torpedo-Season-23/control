#include "UART.h"
#define WAITING_TIME 20

long lastUARTReceiveTime= millis();
SoftwareSerial serialYZ(RX_Y, TX_Y);
long current=5;
void UART_YZ::begin() {
  serialYZ.begin(9600);
}

void UART_YZ::receiveFrame(uint8_t* data) {
  uint8_t frame[UDP_SEND_FRAME];
  current= millis();
  while (millis()-current< WAITING_TIME) {
    byte x;
    x = this->readByte();
    if (x != '(') continue;
    for (int i = 0; i < UDP_SEND_FRAME; i++) {
      frame[i] = this->readByte();
    }
    x = this->readByte();
    if (x != ')') continue;
      for(int i= 0;i<UDP_SEND_FRAME;i++)
        data[i]= frame[i];
    lastUARTReceiveTime= millis();
    
#ifdef PRINT_ON
    for (int i = 0; i < UDP_SEND_FRAME; i++) {
      Serial.print(data[i]);
      Serial.print(" ");
    }
    Serial.println();
    Serial.println("Received From Sensors!");
    Serial.print("Angles: ");
    for (int i = ANGLE_INDEX; i < PRESSURE_INDEX; i += 2) {
      int x = data[i] << 8 | data[i + 1];
       Serial.print(x);
       Serial.print(" ");
    }
    Serial.print(" Pressure: ");
    int y = data[PRESSURE_INDEX] << 8 | data[PRESSURE_INDEX + 1];
    Serial.print(y);
    Serial.print(" ");
#endif
    return;
  }
  if(millis()-lastUARTReceiveTime>2000){
    Serial.print("Failed to Receive from UART!");
    for(int i= 0;i<UDP_SEND_FRAME;i++)
      data[i]= 255;
  }
}

void UART_YZ::sendFrame(uint8_t* sendingFrame) {
  serialYZ.write('(');
  serialYZ.write(sendingFrame, UDP_REC_FRAME);
  serialYZ.write(')');
  
}


inline byte UART_YZ::readByte() {
  if(millis()-current > WAITING_TIME)
    return -1;
  while ((!serialYZ.available()) && (millis()-current < WAITING_TIME));
  uint8_t x=serialYZ.read();
  //Serial.println(x);
  return x;
}

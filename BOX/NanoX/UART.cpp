#include "UART.h"
#include "Converter.h"
//Converter converter;
#define WAITING_TIME 30

long lastUARTReceiveTime= millis();
SoftwareSerial serialYZ(RX_Y, TX_Y);
long current=5;
void UART_YZ::begin() {
  serialYZ.begin(9600);
}

void UART_YZ::receiveFrame(uint8_t* data) {
  //return;
  /*this->readByte();
  return;*/
  uint8_t frame[16];
  current= millis();
  while (millis()-current< WAITING_TIME) {
    byte x;
    x = this->readByte();
    if (x != '(') continue;
    for (int i = 0; i < 16; i++) {
      frame[i] = this->readByte();
    }
    x = this->readByte();
    if (x != ')') continue;
      for(int i= 0;i<16;i++)
        data[i]= frame[i];
    lastUARTReceiveTime= millis();
    
#ifdef PRINT_ON
    for (int i = 0; i < 16; i++) {
      Serial.print(data[i]);
      Serial.print(" ");
    }
    Serial.println();
    Serial.println("Received From Sensors!");
    Serial.print("Angles: ");
    for (int i = ANGLE_INDEX; i < PRESSURE_INDEX; i += 2) {
      int x = data[i] << 8 | data[i + 1];
      // Serial.print(x);
      // Serial.print(" ");
    }
    Serial.print(" Pressure: ");
    int y = data[PRESSURE_INDEX] << 8 | data[PRESSURE_INDEX + 1];
    Serial.print(y);
    Serial.print(" ");

    Serial.print("Leakage: ");
    for (int i = LEAKAGE_INDEX; i < LEAKAGE_INDEX + 8; i++) {
      int z = data[i];
      Serial.print(z);
      Serial.print(" ");
    }
    Serial.println();
#endif
    return;
  }
  if(millis()-lastUARTReceiveTime>2000){
    Serial.print("Failed to Receive from UART!");
    for(int i= 0;i<16;i++)
      data[i]= 255;
  }
}

void UART_YZ::sendFrame(uint8_t* sendingFrame) {

  //Serial.print("UART Sent Frame: ");
  for (int i = 0; i < 8; i++) {
    this->rec_frame[i] = sendingFrame[i];
    //Serial.print(sendingFrame[i]);
    //Serial.print(" ");
    // this->rec_frame[i] = this->counter++;
  }
  //Serial.println();
  serialYZ.write('(');
  serialYZ.write(this->rec_frame, UDP_REC_FRAME);
  serialYZ.write(')');
  /*Serial.write('(');
  Serial.write(this->rec_frame, UDP_REC_FRAME);
  Serial.write(')');*/
  
}


inline byte UART_YZ::readByte() {
  //Serial.println(current);
  
  if(millis()-current > WAITING_TIME)
    return -1;
  while ((!serialYZ.available()) && (millis()-current < WAITING_TIME));
  //while (!serialYZ.available());
  uint8_t x=serialYZ.read();
  //Serial.println(x);
  return x;
}

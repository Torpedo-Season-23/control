#include "UART_Y.h"
#include "Converter.h"
//Converter converter;

SoftwareSerial serialY(RX_Y, TX_Y);
void UART_Y::begin() {
  serialY.begin(9600);
}

void UART_Y::receiveFrame(uint8_t* data) {
  while (1) {
    byte x;
    
    x = this->readByte();
    // Serial.println("torpedo");
    if (x != '(') continue;
    for (int i = 0; i < 16; i++) {
      data[i] = this->readByte();
    }
    x = this->readByte();
    if (x != ')') continue;

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
      Serial.print(x);
      Serial.print(" ");
    }
    Serial.print(" Pressure: ");
    int y = data[PRESSURE_INDEX] << 8 | data[PRESSURE_INDEX + 1];
    Serial.println(y);
    Serial.print(" ");

    Serial.print("Leakage: ");
    for (int i = LEAKAGE_INDEX; i < 16; i++) {
      int z = data[i];
      Serial.print(z);
      Serial.print(" ");
    }
    #endif
    return;
  }
}

void UART_Y::sendFrame(uint8_t* sendingFrame) {

  for (int i = 0; i < 8; i++) {
    this->rec_frame[i] = sendingFrame[i];
    // this->rec_frame[i] = this->counter++;
  }
  serialY.write('(');
  serialY.write(this->rec_frame, UDP_REC_FRAME);
  serialY.write(')');
}


inline byte UART_Y::readByte(){
  while (!serialY.available());
  uint8_t x=serialY.read();
  Serial.print("Byte: ");
  Serial.print(x);
  return x; 
}

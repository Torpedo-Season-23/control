#include "UART.h"
#include "Converter.h"
//Converter converter;

SoftwareSerial serialYZ(RX_Y, TX_Y);
void UART_YZ::begin() {
  serialYZ.begin(9600);
}

void UART_YZ::receiveFrame(uint8_t* data) {
  //return;
  while (1) {
    byte x;
    x = this->readByte();
    Serial.println("HERE");
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
    Serial.print(y);
    Serial.print(" ");

    Serial.print("Leakage: ");
    for (int i = LEAKAGE_INDEX; i < UART_YZ_FRAME_SIZE; i++) {
      int z = data[i];
      Serial.print(z);
      Serial.print(" ");
    }
#endif
    return;
  }
}

void UART_YZ::sendFrame(uint8_t* sendingFrame) {

  Serial.print("UART Sent Frame: ");
  for (int i = 0; i < 8; i++) {
    this->rec_frame[i] = sendingFrame[i];
    Serial.print(sendingFrame[i]);
    Serial.print(" ");
    // this->rec_frame[i] = this->counter++;
  }
  Serial.println();
  serialYZ.write('(');
  serialYZ.write(this->rec_frame, UDP_REC_FRAME);
  serialYZ.write(')');
}


inline byte UART_YZ::readByte() {
  while (!serialYZ.available());
  uint8_t x=serialYZ.read();
  Serial.print(x);
  return x;
}

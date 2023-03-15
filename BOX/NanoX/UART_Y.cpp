#include "UART_Y.h"
#include "Converter.h"
Converter converter;

SoftwareSerial serialY(RX_Y, TX_Y);
Converter conv;
void UART_Y::begin() {
  serialY.begin(9600);
}

void UART_Y::receiveFrame(uint8_t* data) {

  while (1) {

    byte x;
    while (!serialY.available())
      ;
    x = serialY.read();
    if (x != '(') continue;

    for (int i = 0; i < UART_y_FRAME_SIZE; i++) {
      while (!serialY.available())
        ;
      data[i] = serialY.read();
    }

    while (!serialY.available())
      ;
    x = serialY.read();
    if (x != ')') continue;


    //*********DEBUGGING*********//

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
    for (int i = LEAKAGE_INDEX; i < UART_y_FRAME_SIZE; i++) {
      int z = data[i];
      Serial.print(z);
      Serial.print(" ");
    }
    for (int i = Converters_INDEx; i < Converters_INDEx + 6; i++) {
      converter.checkConverter(this->rec_frame);
      data[i] = conv.Set_data();
      // data[i] = conv.Debug();
    }

    return;
  }
}

void UART_Y::sendFrame(uint8_t* sendingFrame) {
  for (int i = 0; i < 8; i++) {
    this->rec_frame[i] = sendingFrame[i];
  }
  serialY.write('(');
  serialY.write(sendingFrame, UDP_REC_FRAME);
  serialY.write(')');
}
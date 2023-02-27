#include "UART_Y.h"
#include "Converter.h"

Converter conv;
SoftwareSerial serialY(RX_Y, TX_Y);

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
    for (int i = 0; i < UART_y_FRAME_SIZE - 2; i++) {
      while (!serialY.available())
        ;
      data[i] = serialY.read();
    }
    while (!serialY.available())
      ;
    x = serialY.read();
    if (x != ')') continue;
    for (int i = 0; i < 8; i++) {
      Serial.print(data[i]);
      Serial.print(" ");
    }
    Serial.println();
    Serial.println("Received From Sensors!");
    //uint8_t count= 0;
    Serial.print("ANgles: ");
    for (int i = ANGLE_INDEX; i < 6; i += 2) {
      int x = data[i] << 8 | data[i + 1];
      Serial.print(x);
      Serial.print(" ");
    }
    Serial.print(" Pressure: ");
    int y = data[PRESSURE_INDEX] << 8 | data[PRESSURE_INDEX + 1];
    Serial.println(y);

    for (int i = Converters_INDEx; i < Converters_INDEx + 4 ; i++) {
      data[i] = conv.get_data();
    }
    return;
  }
  // void UART_Y::PrepareFram(uint8_t * Converter_data) {

  //   for () {
  //   }
  // }

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
  //sendingFrame[1]= '(';
  //sendingFrame[1+4]= ')';
  serialY.write('(');
  serialY.write(sendingFrame, 13);
  serialY.write(')');
}

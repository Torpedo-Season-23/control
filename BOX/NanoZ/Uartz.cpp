#include "Uartz.h"

SoftwareSerial serial(RX_Z, TX_Z);

void Uartz::startUart() {
  serial.begin(9600);
}

void Uartz::receiveFrame() {
  uint8_t frame[UART_Z_FRAME_SIZE];

  while (true) {
    byte x;
    Serial.println("Entered");
    while (!serial.available());
    Serial.println("Enteredjjj");
    x = serial.read();
    if (x != '(') continue;
    for (int i = 0; i < ACTUAL_DATA; i++) {
      while (!serial.available())
        ;
      frame[i] = serial.read();
    }
    while (!serial.available())
      ;
    x = serial.read();
    if (x != ')') continue;


    for (int i = 0; i < 8; i++) {
      uartFrame[i] = frame[i];
    }

//debuging
#ifdef UART_PRINT_ON
    Serial.print("Frame is ");
    for (int i = 0; i < ACTUAL_DATA; i++) {
      Serial.print(uartFrame[i]);
      Serial.print(" ");
    }
#endif

    return;
  }
}

void Uartz::extractData(uint16_t *thrustersFrame, uint8_t *toolsFrame) {

  uint8_t loopLimit = max(MOTORS_COUNT, TOOLS_COUNT);

  for (int i = 0; i < loopLimit; i++) {

    //Extract Motors directions byte (the second byte) & Motors speeds (form 2 to 7)
    if (i < MOTORS_COUNT) {
      //directions byte
      int8_t dir = (uartFrame[DIRECTIONS_BYTE_INDEX] & 1 == 1) ? 1 : -1;
      //Motors speeds
      uint16_t speedChange = map(uartFrame[i + MOTORS_SPEEDS_INDEX], 0, 255, 0, 400);
      uint16_t speedValue = 1500 + dir * speedChange;
      //check the limits
      if (speedValue > MOT_MAX_SPEED) speedValue = MOT_MAX_SPEED;
      if (speedValue < MOT_MIN_SPEED) speedValue = MOT_MIN_SPEED;
      thrustersFrame[i] = speedValue;
#ifdef THRUSTERS_PRINT_ON
      Serial.print(uartFrame[DIRECTIONS_BYTE_INDEX] & 1);
#endif
      uartFrame[DIRECTIONS_BYTE_INDEX] >>= 1;
    }

    //Extract tools byte (the first byte in uartFrame)
    if (i < TOOLS_COUNT) {

      if (uartFrame[ACC_BYTE_INDEX] & 1 == 1) {
        toolsFrame[i] = 255;
      } else {
        toolsFrame[i] = 0;
      }
#ifdef ACC_PRINT_ON
      Serial.print(uartFrame[ACC_BYTE_INDEX] & 1);
#endif
      uartFrame[ACC_BYTE_INDEX] >>= 1;
    }
  }
  Serial.println();

  //Debuging
#ifdef THRUSTERS_PRINT_ON
  for (int i = 0; i < MOTORS_COUNT; i++) {
    Serial.print(thrustersFrame[i]);
    Serial.print(" ");
  }
  Serial.println();
#endif
  //Debuging
#ifdef ACC_PRINT_ON
  for (int i = 0; i < TOOLS_COUNT; i++) {
    Serial.print(toolsFrame[i]);
    Serial.print(" ");
  }
  Serial.println();
#endif
}

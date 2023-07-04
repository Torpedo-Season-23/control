#include "Uartz.h"




void Uartz::receiveFrame(uint8_t *frame) {
  for(int i= 0;i<8;i++)
    this->uartFrame[i]= frame[i];
}
void Uartz::extractData(unsigned int *thrustersFrame, uint8_t *toolsFrame) {
  uint8_t loopLimit = 8;
 
  for (int i = 0; i < 8; i++) {

    //Extract Motors directions byte (the second byte) & Motors speeds (form 2 to 7)
    if (i < 6) {
      //directions byte
      int dir = (uartFrame[1] & 1 == 1) ? 1 : -1;
      //Motors speeds
      unsigned int speedChange = uartFrame[i + 2];
      unsigned int speedValue = 1500 + dir * speedChange;
      //check the limits
      if (speedValue > 1900) speedValue = 1900;
      if (speedValue < 1100) speedValue = 1100;
      thrustersFrame[i] = speedValue;
      uartFrame[1] >>= 1;
    }
        //Extract tools byte (the first byte in uartFrame)
    if (i < 8) {

      if (uartFrame[0] & 1 == 1) {
        toolsFrame[i] = 255;
      } else {
        toolsFrame[i] = 0;
      }
    }
      uartFrame[0] >>= 1;
    }
}


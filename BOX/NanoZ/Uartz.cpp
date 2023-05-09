#include "Uartz.h"
long currentUART= millis();
long lastTimeRead= millis();
bool onHigh=false;


void Uartz::startUart() {
}

void Uartz::sendFrame(){
  uint8_t frame[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  Serial.write('(');
  Serial.write(frame,16);
  Serial.write(')');
}

void Uartz::receiveFrame() {
  //return;
    //serial.begin(9600);
    
  uint8_t frame[UART_Z_FRAME_SIZE];
  currentUART= millis();

 Serial.println("Starting Frame: ");
  while (true) {
   //Serial.end();
    //Serial.begin(9600);
    byte x;
    int y= 0;
   

    x = readByte();
    if (x != '(') continue;
    for (int i = 0; i < 8; i++) {
      frame[i] = readByte();
      //Seri)al.print(frame[i]);
      //Serial.print(" ");
      
    }
    x =readByte();
    // Serial.print("\n---------------------Ending Frame is ");
    //Serial.println(x);
    if (x != ')') continue;
    Serial.println("Success!");
    

    for (int i = 0; i < ACTUAL_DATA; i++) {
      uartFrame[i] = frame[i];
    }
    
    lastTimeRead= millis();

//debuging
#ifdef UART_PRINT_ON
    // Serial.print("Frame is ");
    for (int i = 0; i < ACTUAL_DATA; i++) {
      Serial.print(uartFrame[i]);
      Serial.print(" ");
    }
#endif
    //serial.end();
    return;
  }
  // Serial.print("HERE");
  if(millis()-lastTimeRead > 3000){
    /*if(onHigh)
      uartFrame[0]= 255;
    else 
      uartFrame[0]= 0;
      onHigh= !onHigh;
  }
      
    delay(1000);*/
  }  
}

void Uartz::extractData(uint16_t *thrustersFrame, uint8_t *toolsFrame) {
  uint8_t loopLimit = max(MOTORS_COUNT, TOOLS_COUNT);
  // for(int i= 0;i<8;i++)
  //   if(uartFrame[ACC_BYTE_INDEX] & 1 == 1){
  //     toolsFrame[i]= 255;
  //   }
  //   else{
  //     toolsFrame[i]= 0;
  //   }
  //  return;

  for (int i = 0; i < 8; i++) {

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
    }
    
#ifdef ACC_PRINT_ON
      Serial.print(uartFrame[ACC_BYTE_INDEX] & 1,BIN);
#endif
      uartFrame[ACC_BYTE_INDEX] >>= 1;
    }
    
  // Serial.println();


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
    Serial.print("--");
  }
  Serial.println();
#endif
}

inline byte Uartz::readByte(){
  while(!Serial.available());

  byte x= Serial.read();
  // Serial.println((char)x);
  return x;
}

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
    for (int i = 0; i < ACTUAL_DATA; i++){
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
 
//extract Accessories data
  for(int i= 0; i < TOOLS_COUNT;i++){
    if(uartFrame[ACC_BYTE_INDEX] & 1 == 1){
      toolsFrame[i]= 255;
    }
    else{
      toolsFrame[i]= 0;
    }
    uartFrame[ACC_BYTE_INDEX] >>= 1;
  }

//extract Thrusters Speeeds
int j = 0 ;
  for (int i = 1; i < ACTUAL_DATA ; i +=2)
  {
    uint16_t speedValue = (uartFrame[i+1] << 8 ) | uartFrame[i] ; 

    if (speedValue > MOT_MAX_SPEED) speedValue = MOT_MAX_SPEED;
    if (speedValue < MOT_MIN_SPEED) speedValue = MOT_MIN_SPEED;
    
    thrustersFrame[j] = speedValue;
    j++;
  }
  
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

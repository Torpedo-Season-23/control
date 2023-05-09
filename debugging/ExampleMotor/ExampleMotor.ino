#include "Servo.h"

Servo motors[6];
int pins[]= { 9,3,11, 10, 5,6};
void setup() {
  for(int i= 0;i<6;i++){
    motors[i].attach(pins[i]);
    motors[i].writeMicroseconds(1500);
  }
  delay(2000);
  
}

void write(int value){
  for(int i= 0;i<6;i++)
    motors[i].writeMicroseconds(value);
}
void loop() {
  
  for(int i=0;i<250;i+=50){
    write(1500+i);
    delay(250);
  }
  delay(2000);
  for(int i=200;i>=0;i-=50){
    write(1500+i);
    delay(100);
  }
  delay(3000);
}

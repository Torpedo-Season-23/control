#include <Arduino.h> 
#include <Servo.h>
#ifndef Motor_H_
#define Motor_H_

#define motor1_pin 5
#define motor2_pin 10
#define pot_pin  A0 

class Motor{

Servo servo;
private:
void attach_motors();
public:
void get_speed();

};
#endif
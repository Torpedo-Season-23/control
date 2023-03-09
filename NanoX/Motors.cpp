#include "Motors.h"
void Motor::attach_motors() {
  servo.attach(motor1_pin);
  servo.attach(motor2_pin);
  servo.writeMicroseconds(1500);
  delay(1000);
}
void Motor::get_speed() {
  attach_motors();
  float reading = analogRead(pot_pin);
  float map_reading = map(reading, 0, 1024, 1500, 1900);
  Serial.println(map_reading);
  servo.writeMicroseconds(map_reading);
}
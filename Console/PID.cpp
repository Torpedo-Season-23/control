#include "PID.h"
#include <Arduino.h>

void PID::setSetpoint(float setpoint) {
  this->setpoint = setpoint;
}
void PID::update(float sensor_value) {
  int x, sum, factor, m;
  int* array = this->controller->get_hframe();
  this->input = sensor_value;
  if (array[2] != 0) {
    this->setSetpoint(sensor_value);
    return;
  }
  this->compute();
  Serial.print("PID error\t");
  Serial.println(this->error);
  m = max(array[0], array[1]);
  x = m * tan(this->error);
  sum = abs(array[0]) + abs(array[1]) + abs(x);
  factor = m / sum;
  array[0] *= factor;
  array[0] *= factor;
  array[0] = x * factor;
  this->controller->set_hframe(array);
}

void PID::setPIDFactors(float* arr) {
  this->Kp = arr[0];
  this->Ki = arr[1];
  this->Kd = arr[2];
}

void PID::updateDepth(float sensor_value) {
  int* array = this->controller->get_vframe();
  if(array[0]!=1500||array[0]!=1500){
    this->error=0;
    if(sensor_value<1300)this->setSetpoint(sensor_value);
    return;
  }
  this->input = sensor_value;
  this->compute();
  if (this->error < -400) {
    this->error = -400;
  }
  if (this->error > 400) {
    this->error = 400;
  }
  array[0]=this->error+1500;
  array[1]=this->error+1500;
  Serial.print("setpoint : ");
  Serial.print(this->setpoint);
  Serial.print("    ");
  Serial.print("error : ");
  Serial.print(-this->error);
  Serial.print("    ");
  Serial.print("Factor : ");
  Serial.print(this->Kp);
  Serial.print("    ");
  Serial.print(this->Ki);
  Serial.print("    ");
  Serial.print(this->Kd);
  Serial.print("    ");

  Serial.println();
  this->controller->set_vframe(array);

}


void PID::compute() {
  double now = millis();
  this->deltatime = now - this->prev_time;
  if (this->deltatime == 0) {
    this->error = 0;
  }
  else if (abs(this->input-this->setpoint)<5){
    this->error=0;
  } 
  else if(abs(this->input)>1300){
    this->error = 0;

  } 
  else {
    this->sumError += (this->setpoint - this->input) * (this->deltatime);
    this->error = this->Kp * (this->setpoint - this->input) + this->Ki * (this->sumError) + this->Kd * ((this->setpoint - this->input - this->lastError) / this->deltatime);
    this->lastError = this->setpoint - this->input;
    this->prev_time = now;
  }
};
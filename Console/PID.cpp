// #include "PID.h"
// #include <Arduino.h>

// void PID::setSetpoint(float setpoint){
//   this->setpoint=setpoint;
// }
// void PID::update(float sensor_value) {
//   int x, sum, factor, m;
//   this->input = sensor_value;
//   this->compute();
//   Serial.print("PID error\t");
//   Serial.println(this->error);
//   int* array = this->controller->get_hframe;
//   if (array[2] != 0) return;
//   m = max(array[0], array[1]);
//   x = m * tan(this->error);
//   sum = abs(array[0]) + abs(array[1]) + abs(x);
//   factor = m / sum;
//   array[0] *= factor;
//   array[0] *= factor;
//   array[0] = x * factor;
//   this->controller->set_hframe(array);
// }
// void PID::compute() {
//   double now = millis();
//   this->timeSlice = now - this->previous_time;
//   if (this->timeSlice == 0)
//     this->error = 0;
//   else {
//     this->sumError += (this->setpoint - this->input) * (this->timeSlice);
//     this->error = this->Kp * (this->setpoint - this->input) + this->Ki * (this->sumError) + this->Kd * ((this->setpoint - this->input - this->lastError) / this->timeSlice);
//     this->lastError = this->setpoint - this->input;
//     previous_time = now;
//   }
// };
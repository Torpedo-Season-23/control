#include "PID.h"
#include <Arduino.h>
void PID::setSetpoint(){
    this->setpoint=0;
}
 void  PID::update(float sensor_value){
                this->input=sensor_value;
                this->compute();
                Serial.print("PID error\t");
                Serial.println(this->error);
                }

 void PID::compute(){
            double now=millis();
            this->timeSlice=now-this->previous_time;
            if(this->timeSlice==0)
              this->error=0;
            else
              { this->sumError+=(this->setpoint-this->input)*(this->timeSlice);
                this-> error=this->Kp*(this->setpoint-this->input)+this->Ki*(this->sumError)+this->Kd*((this->setpoint-this->input-this->lastError)/this->timeSlice);
                this->lastError=this->setpoint-this->input;
                previous_time=now;}};
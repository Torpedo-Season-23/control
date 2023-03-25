// #ifndef __PID__H
// #define __PID__H
// #include "IController.h"

// class PID{
//     private:
//         float Kp,Ki,Kd;
//         float input=0;
//         float setpoint=0;
//         float error=0;
//         float sumError=0;
//         float lastError=0;
//         float deltatime=0;
//         float prev_time=0;
//         IController *controller;
//     public:
//         PID(IController *controller,float Kp, float Ki, float Kd){
//             this->Kp=Kp;
//             this->Ki=Ki;
//             this->Kd=Kd;
//             this->controller=controller;};
//         void compute();
//         void update(float sensor_value);
//         void setSetpoint(float setpoint);
//          };


// #endif
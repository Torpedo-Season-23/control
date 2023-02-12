#ifndef UartX_H_
#define  Uart_H_
#include <Arduino.h>
#include <SoftwareSerial.h>

#define Imu_Angles_Index 0
#define PRESSURE_index  Imu_Angles_Index+3*2

class Nano_X{
public: 
    uint16_t IMU_Angles[3];
    int pressure;
SendData (){
 this->IMU_Angles [0]=0;
 this->IMU_Angles [1]=0;
 this->IMU_Angles [2]=0;
 this->pressure=0 ;
    }
void Start_Uart();
void Set_IMU_Angles(int angles[3]);
void Set_Pressure(int Pressure);
void Prepare_frame(uint8_t Datafram[8]);
void Send_Data();
void receive();
};
#endif

#ifndef MOTOR_H
#define MOTOR_H
#include "Arduino.h"
#include "config.h"
#define GET_POSITIVE_SPEED(x) (x > MOTOR_STATIC_SPEED ? (x - MOTOR_STATIC_SPEED) : (MOTOR_STATIC_SPEED - x))

class Motor
{
private:
    uint16_t currentSpeed;
     // Parameter in the exponential equation
    long lastUpdatedTime;
    void increaseSpeed(uint16_t);
    void decreaseSpeed(uint16_t);
    void changeDirection(uint16_t);

public:
    Motor()
    {
        this->currentSpeed = MOTOR_STATIC_SPEED;
        this->lastUpdatedTime  = millis();
        this->counter = 0;
    }
    uint8_t counter;
    void setSpeed(uint16_t newSpeed);
    uint16_t getSpeed(){
        if(this->currentSpeed > MOTOR_HIGHEST_SPEED)
            this->currentSpeed= MOTOR_HIGHEST_SPEED;
        else if(this->currentSpeed < MOTOR_LOWEST_SPEED)
            this->currentSpeed= MOTOR_LOWEST_SPEED;
        return this->currentSpeed;};
};

class Motors
{
private:
    float exponent;
    float timeStep; // Time between every 2 updates
    Motor motors[MOTORS_NUMBER];
    void print();

public:
    Motors(){};
    void update(int*);
};


#endif
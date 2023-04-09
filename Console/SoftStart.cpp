#include "SoftStart.h"

/**
 * We have 3 different conditions
 * 1: We are increasing the speed.
 * 2: We are decreasing the speed or stopping.
 * 3: We are changing directions
 */
void Motor::setSpeed(uint16_t newSpeed){
    if(newSpeed == this->currentSpeed){
        // this->counter = 0;
        return ;
       
    }
    long currentTime= millis();  
    if(currentTime- this->lastUpdatedTime < 100)
        return ;
    this->lastUpdatedTime= currentTime;
    if (newSpeed > 1500)// Forward is required.
    { 
        if (this->currentSpeed > newSpeed)this->decreaseSpeed(newSpeed);
        else if (this->currentSpeed >= 1500)this->increaseSpeed(newSpeed);
        else this->changeDirection(newSpeed);
        return ;
    }
    if(this->currentSpeed < newSpeed)this->decreaseSpeed(newSpeed);
    else if(this->currentSpeed<=1500) this->increaseSpeed(newSpeed);
    else this->changeDirection(newSpeed);
    return ;
}

void Motor::increaseSpeed(uint16_t newSpeed){
    uint16_t positiveRequiredSpeed= GET_POSITIVE_SPEED(newSpeed);
    uint16_t positiveCurrentSpeed= GET_POSITIVE_SPEED(this->currentSpeed);
    if(this->counter == 0 ){
        this->counter= (uint8_t) (log2(0.39*positiveCurrentSpeed)+1);
    }
    if(this->counter < 10)
        this->counter++;
    uint16_t newCalculatedSpeed= ((1<<this->counter)*INCREAMENT_FACTOR < positiveRequiredSpeed) ? (1<<this->counter)*INCREAMENT_FACTOR :positiveRequiredSpeed; //New Speed is 2^(d+1)
    this->currentSpeed= newSpeed > MOTOR_STATIC_SPEED ? newCalculatedSpeed + MOTOR_STATIC_SPEED :MOTOR_STATIC_SPEED-newCalculatedSpeed; 
}
void Motor::decreaseSpeed(uint16_t newSpeed){
    this->counter= 0;
    this->currentSpeed=newSpeed;
}
void Motor::changeDirection(uint16_t newSpeed){
    this->counter= 0;
    this->currentSpeed= MOTOR_STATIC_SPEED;
}

//Motors Class
void Motors::print(){
    for(int i=0;i<MOTORS_NUMBER;i++){
        Serial.print(this->motors[i].getSpeed());
    Serial.print("  ");

    }

    for(int t = 0 ; t < MOTORS_NUMBER ; t++){
      Serial.print(this->motors[t].counter);
    }
    
    Serial.println();
}
void Motors::update(int* motorsValues){
    for(int i= 0;i<MOTORS_NUMBER;i++){
        this->motors[i].setSpeed(motorsValues[i]);
        motorsValues[i]= this->motors[i].getSpeed();
    }
    //this->print();
}

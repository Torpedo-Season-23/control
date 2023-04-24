#ifndef INDEX_CONV_H
#define INDEX_CONV_H
#include <Arduino.h>


class IndexConverter{
   public:
    void init(uint16_t* originalFrame){
        this->thrusterPointers[FRONT_LEFT]=&originalFrame[0];
        this->thrusterPointers[FRONT_RIGHT]=&originalFrame[1];
        this->thrusterPointers[BACKWARD_LEFT]=&originalFrame[2];
        this->thrusterPointers[BACKWARD_RIGHT]=&originalFrame[3];
        this->thrusterPointers[UPPER_FRONT]=&originalFrame[4];
        this->thrusterPointers[UPPER_BACK]=&originalFrame[5];
    }
    uint16_t* updateArray(){
        for(int i= 0;i<MOTORS_NUMBER;i++)
            newFrame[i]= *this->thrusterPointers[i];
        return newFrame;
    }
   private:
   uint16_t* thrusterPointers[MOTORS_NUMBER]; 
   uint16_t newFrame[MOTORS_NUMBER];
};
#endif

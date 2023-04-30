#ifndef INDEX_CONV_H
#define INDEX_CONV_H
#include <Arduino.h>


// #define FRONT_LEFT  1//1
// #define FRONT_RIGHT 2 //2 *
// #define BACKWARD_LEFT 3 //3*//ma3kos
// #define BACKWARD_RIGHT 5 //5*

// #define UPPER_BACK 0 //0*
// #define UPPER_FRONT 4 //4*
class IndexConverter{
   public:
    void init(uint16_t* originalFrame){
        this->thrusterPointers[BACKWARD_LEFT]=&originalFrame[0];// 2  // back left
        this->thrusterPointers[FRONT_LEFT]=&originalFrame[1]; //5 //front left
        this->thrusterPointers[BACKWARD_RIGHT]=&originalFrame[2]; // 1 * backward right
        this->thrusterPointers[FRONT_RIGHT]=&originalFrame[3]; //3 * //front right
        this->thrusterPointers[UPPER_FRONT]=&originalFrame[4]; //4
        this->thrusterPointers[UPPER_BACK]=&originalFrame[5]; //0 *
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

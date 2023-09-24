#ifndef INDEX_CONV_H
#define INDEX_CONV_H
#include <Arduino.h>


#define FRONT_LEFT 5  //1           2
#define FRONT_RIGHT 2 //2 * mmmmmmmm  0
#define BACKWARD_LEFT 1 //4*         4
#define BACKWARD_RIGHT 3 //5 mmmmm  1


#define UPPER_FRONT 4 //3*       3
#define UPPER_BACK 0 //0*

class IndexConverter{
   public:
    void init(uint16_t* originalFrame){
        this->thrusterPointers[FRONT_RIGHT]=&originalFrame[FRONT_RIGHT];// 2  // back left
        this->thrusterPointers[BACKWARD_RIGHT]=&originalFrame[BACKWARD_RIGHT]; //5 //front left
        this->thrusterPointers[FRONT_LEFT]=&originalFrame[FRONT_LEFT]; // 1 * backward right
        this->thrusterPointers[BACKWARD_LEFT]=&originalFrame[BACKWARD_LEFT]; //3 * //front right
        this->thrusterPointers[UPPER_FRONT]=&originalFrame[UPPER_FRONT]; //4
        this->thrusterPointers[UPPER_BACK]=&originalFrame[UPPER_BACK]; //0 *
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

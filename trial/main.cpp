#include <iostream>
#include "Uartz.h"
using namespace std;

Uartz z;
int main(){
    uint8_t frame[8]= {0,0b11001100,200,200,200,200,200,200};
    z.receiveFrame(frame);
    unsigned int thrusters[6];
    unsigned char tools[8];

    z.extractData(thrusters,tools);
    cout<< "Thrusters: ";
    for(int i= 0;i<6;i++)
        cout<<thrusters[i]<<" ";
    cout<<endl;
    cout<< "Tools: ";
    for(int i= 0;i<8;i++)
        cout<<(int)tools[i]<<" ";
    cout<<endl;
    
}
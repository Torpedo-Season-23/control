#ifndef THRUSTERS_H
#define THRUSTERS_H
#define UpperRight 0
#define BackRight 1
#define UpperLeft 2
#define BackLeft 3
#define Up 4
#define Down 5


class Thrusters{

    
protected:
    int thruster_frame[6]={0}; //UR , BR , UL ,BL , UP , DOWN
public:
    virtual void set_h_forces(int *array)=0;
    virtual void set_v_forces(int *array)=0;
    virtual void soft_start(){};
    virtual int * get_thruster_frame()=0;
};

#endif

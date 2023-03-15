#ifndef THRUSTERS_H
#define THRUSTERS_H
#define UpperRight 0
#define BackRight 1
#define UpperLeft 2
#define BackLeft 3
#define Up 4
#define Down 5


class Thrusters
{
private:
    double config_matrix[4][3]={{-0.35360679, -0.35360679, -0.25879917},
                                {-0.35360679,  0.35360679 , 0.25879917},
                                {0.35360679, -0.35360679 , 0.25879917},
                                {0.35360679  ,0.35360679 ,-0.25879917}};
    int thruster_frame[6]={0}; //UR , BR , UL ,BL , UP , DOWN
public:
    void set_h_forces(int *array);
    void set_v_forces(int *array);
    void soft_start();
    int * get_thruster_frame();

};

#endif

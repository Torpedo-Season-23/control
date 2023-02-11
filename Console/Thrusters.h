#ifndef THRUSTERS_H
#define THRUSTERS_H

class Thrusters
{
private:
    double config_matrix[4][3]={{-0.35360679, -0.35360679, -0.25879917},{-0.35360679,  0.35360679 , 0.25879917},{0.35360679, -0.35360679 , 0.25879917},{0.35360679  ,0.35360679 ,-0.25879917}};
    double thruster_frame[6]={0}; //UR , BR , UL ,BL , UP , DOWN
public:
    void set_h_forces(float *array);
    void set_v_forces(float *array);
    double * get_thruster_frame();

};

#endif

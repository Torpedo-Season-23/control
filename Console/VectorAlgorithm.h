#ifndef VECTOR_ALG_H
#define VECTOR_ALG_H
#include "Thrusters.h"
class VectorAlgorithm : public Thrusters
{

private:
    double config_matrix[4][3] = {{-0.35360679, -0.35360679, -0.25879917},
                                  {-0.35360679, 0.35360679, 0.25879917},
                                  {0.35360679, -0.35360679, 0.25879917},
                                  {0.35360679, 0.35360679, -0.25879917}};

public:
    void set_h_forces(int *array) ;
    void set_v_forces(int *array) ;
//    void soft_start() {;/
     int *get_thruster_frame() ;
};
#endif

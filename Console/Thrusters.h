#ifndef THRUSTERS_H
#define THRUSTERS_H



class Thrusters {
private:
  double config_matrix[4][3] = {[ 0.5 , -0.2886836 ,  0.00594587],
                                [-0.5 , -0.2886836 ,  0.00594587],        
                                [-0.5 , -0.2886836 , -0.00594587],        
                                [ 0.5 , -0.2886836 , -0.00594587]};
  int thruster_frame[6] = { 0 };  //UR , BR , UL ,BL , UP , DOWN
public:
  void set_h_forces(int *array);
  void set_v_forces(int *array);
  int *get_thruster_frame();
};

#endif

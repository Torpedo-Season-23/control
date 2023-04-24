#ifndef THRUSTERS_H
#define THRUSTERS_H

#define UpperRight 0
#define BackRight 1
#define UpperLeft 2
#define BackLeft 3
#define Up 4
#define Down 5
#define Xforce 0
#define Yforce 1
#define Moment 2

class Thrusters {
private:
  double config_matrix[4][3] = {{-0.5    ,     0.2886836 , -1.18979631}, 
                                { 0.5    ,     0.2886836 , -1.18979631}, 
                                { 0.5    ,     0.2886836 ,  1.18979631}, 
                                {-0.5    ,     0.2886836 ,  1.18979631}};
                                
  int thruster_frame[6] = { 0 };  //UR , BR , UL ,BL , UP , DOWN
public:
  void set_h_forces(int *array);
  void set_v_forces(int *array);
  int *get_thruster_frame();
  int speed;
};

#endif

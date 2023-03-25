#ifndef THRUSTERS_H
#define THRUSTERS_H



class Thrusters {
private:
  double config_matrix[4][3] = { { -0.35360679, -0.35360679, -0.25879917 },
                                 { -0.35360679, 0.35360679, 0.25879917 },
                                 { 0.35360679, -0.35360679, 0.25879917 },
                                 { 0.35360679, 0.35360679, -0.25879917 } };
  int thruster_frame[6] = { 0 };  //UR , BR , UL ,BL , UP , DOWN
public:
  void set_h_forces(int *array);
  void set_v_forces(int *array);
  int *get_thruster_frame();
};

#endif

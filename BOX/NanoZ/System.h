#include "Thrusters.h"
#include "Tools.h"
#include "Uartz.h"


class System {
private:
  Thrusters thrusters;
  Thruster thruster;
  Tools tools;
  Uartz uartz;

public:
  System(){};

  void init();
  void getData();
  void setData();
};

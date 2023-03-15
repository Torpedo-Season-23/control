#include "Thrusters.h"
#include "Tools.h"
#include "Uartz.h"


class System {
private:
  Thrusters thrusters;
  Tools tools;
  Uartz uartz;

public:
  System(){};

  void init();
  void getData();
  void setData();
};
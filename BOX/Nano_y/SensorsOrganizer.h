#include "Pressure.h"
#include "TorpedoMPU.h"

class Sensors
{
private:
    PressureSensor pressure;
    TorpedoMPU IMU;

public:
    void init()
    {
        this->pressure.init();
        this->IMU.start();
        this->IMU.check();
    }

    uint16_t getProxyPressure()
    {
        return this->pressure.getPressure();
    }
    int getProxyAngles()
    {
        return this->IMU.getangles();
    }
};
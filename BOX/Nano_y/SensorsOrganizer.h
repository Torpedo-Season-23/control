#include "Pressure.h"
#include "TorpedoMPU.h"
#include "Leakage.h"

class Sensors
{
private:
    PressureSensor pressure;
    TorpedoMPU IMU;
    LeakageSensor leakSensors[8];

public:
    void init()
    {
        this->pressure.init();
        //leakSensors[0].init();
        for (int i = 0; i < SENSORS_NUM; i++)
        {
            this->leakSensors[i].setSensor(i);
        }

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
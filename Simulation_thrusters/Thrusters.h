#ifndef THRUSTERS_H
#define THRUSTERS_H

class ThrustersProcess
{
private:
    double thrustersMatrix[3][4] = {{0.707, 0.707, -0.707, -0.707}, {-0.707, 0.707, -0.707, 0.707}, {0.966, -0.966, -0.966, 0.966}};
    double UT[3][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
    double S_Astred[4][3] = {{0.518, 0, 0}, {0, 0.707, 0}, {0, 0, 0.707}, {0, 0, 0}};
    double V_Transpose[4][4] = {{0.5, -0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5, 0.5}, {-0.5, -0.5, -0.5, 0.5}, {0.5, 0.5, -0.5, 0.5}};
    double UR, UL, BR, BL;

public:
    void processForces(double x, double y, double moment);
    int getUpperRight();
    int getBackRight();
    int getUpperLeft();
    int getBackLeft();
    void multiply(double firstMatrix[][4], double secondMatrix[][3], double **MatA, int rowFirst, int columnFirst, int columnSecond);
};

#endif

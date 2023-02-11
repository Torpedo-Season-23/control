#include"Thrusters.h"
int ThrustersProcess::getBackLeft()
{
  return this->BL;
}
int ThrustersProcess::getBackRight()
{
   return this->BR; 
}
int ThrustersProcess::getUpperLeft()
{
    return this->UL;
}
int ThrustersProcess::getUpperRight()
{
    return this->UR;
}

void ThrustersProcess::processForces (double x, double y, double moment) {
double td[]={x,y,moment};
double MatA[4][3];
multiply(this->V_Transpose,this->S_Astred,MatA,4,4,3);
double MatB[4][3];
multiply(MatA,this->UT,MatB,4,3,3);
double Forces[4][1];
for(i = 0; i < 4; ++i)
	{
		for(j = 0; j < 1; ++j)
		{
			for(k=0; k<3; ++k)
			{
				Forces[i][j] = MatB[i][k] * td[k][j];
			}
		}
	}
this->UR=Forces[0];
this->BR=Forces[1];
this->UL=Forces[2];
this->BL=Forces[3];
}

void multiply(double firstMatrix[][4],double secondMatrix[][3],double (*MatA)[3],int rowFirst,int columnFirst,int columnSecond)
{int i,j,k
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			for(k=0; k<columnFirst; ++k)
			{
				MatA[i][j] = firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}
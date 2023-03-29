#include "Thrusters.h"
#include<iostream>
using namespace std;
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

void ThrustersProcess::processForces(double x, double y, double moment)
{
	double td[] = {x, y, moment};
	double MatA[4][3];
	// multiply(this->V_Transpose, this->S_Astred, MatA, 4, 4, 3);
	// int i, j, k;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				MatA[i][j] += this->V_Transpose[i][k] * this->S_Astred[k][j];
			}
		}
	}
	double MatB[4][3];
	// multiply(MatA, this->UT, MatB, 4, 3, 3);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				MatB[i][j] += MatA[i][k] * this->UT[k][j];
			}
		}
	}
	double Forces[4][1];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				Forces[i][j] += MatB[i][k] * td[k];
			}
		}
	}
	this->UR = Forces[0][0];
	cout<<"Upper Right is "<<this->UR<<endl;
	this->BR = Forces[1][0];
	cout<<"Back Right is "<<this->BR<<endl;

	this->UL = Forces[2][0];
	cout<<"Upper Left is "<<this->UL<<endl;
	
	this->BL = Forces[3][0];
	cout<<"Back Left is "<<this->BL<<endl;

}
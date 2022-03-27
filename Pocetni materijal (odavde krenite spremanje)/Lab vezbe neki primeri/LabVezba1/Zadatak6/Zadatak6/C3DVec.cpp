#include "C3DVec.h"
#include<iostream>
using namespace std;

C3DVec::C3DVec()
{
	vektor= new double[3];

}
C3DVec::C3DVec(double x,double y,double z)
{
	vektor=new double[3];
	vektor[0]=x;
	vektor[1]=y;
	vektor[2]=z;
}
double C3DVec::Dot(C3DVec Vektor)
{
	double rez=0.0;
	for (int i=0;i<3;i++)
		rez +=this->vektor[i]*Vektor.vektor[i];
	return rez;
}
C3DVec C3DVec::Cross(C3DVec Vektor)
{
	C3DVec S;
	
	S.vektor[0]=this->vektor[1]*Vektor.vektor[2] - Vektor.vektor[1]*this->vektor[2];
	S.vektor[1]=this->vektor[0]*Vektor.vektor[2] - Vektor.vektor[0]*this->vektor[2];
	S.vektor[2]=this->vektor[0]*Vektor.vektor[1] - Vektor.vektor[0]*this->vektor[1];

	return S;
}
void C3DVec::stampaj()
{
	cout<<"Vektor:"<<endl;
	cout<<"["<<this->vektor[0]<<" "<<this->vektor[1]<<" "<<this->vektor[2]<<"]"<<endl;
}
C3DVec::~C3DVec(void)
{
}

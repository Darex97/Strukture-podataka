#include "Cpolynom.h"
#include <iostream>
using namespace std;

Cpolynom::Cpolynom(void)
{
	coef=NULL;
	order=-1;
}
Cpolynom::Cpolynom(int order)
{
	this->order=order;
	coef=new double[order+1];
	for(int i=0;i<=order;i++)
		coef[i]=0;
}
void Cpolynom::Coef(int exp,double coef)
{
	this->coef[exp]=coef;
}
Cpolynom& Cpolynom::Derivate(int n)
{
	double temp;
	Cpolynom tmp(this->order);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<tmp.order;j++)
		{
		tmp.coef[j]=this->coef[j+1]*(j+1);
		}
		tmp.order--;
	}
	return tmp;
}
void Cpolynom::stampaj()
{
	for(int i=this->order;i>0;i--)
	{
		cout<<this->coef[i]<<"x^"<<i<<" + ";
	}
	cout<<this->coef[0]<<endl;
}
Cpolynom::~Cpolynom(void)
{
}

#include "Polinom.h"
#include<iostream>
using namespace std;

Polinom::Polinom(void)
{
}
Polinom::Polinom(int order)
{
	this->stepen=order;
	nizkoef=new double[order+1];
	for (int i=0;i<=stepen;i++)
		this->nizkoef[i]=0;
}
void Polinom::Coefs(int* exp,double* coef,int no)
{
	for (int i=0;i<no;i++)
		this->nizkoef[exp[i]]=coef[i];
}
void Polinom::Sub(Polinom& p1,Polinom& p2)
{
	if (p1.stepen >= p2.stepen)
	{
		this->stepen=p1.stepen;
		this->nizkoef=new double[this->stepen + 1];
		for (int i=0;i<=this->stepen;i++)
			this->nizkoef[i]=0;

		for (int i=0;i<=p2.stepen;i++)
			this->nizkoef[i]=this->nizkoef[i] + p2.nizkoef[i];
		for (int i=0;i<=p1.stepen;i++)
			this->nizkoef[i]=p1.nizkoef[i] - this->nizkoef[i];
	}
	else
	{
		this->stepen=p2.stepen;
		this->nizkoef=new double[this->stepen + 1];
		for (int i=0;i<=this->stepen;i++)
			this->nizkoef[i]=0;

		for (int i=0;i<=p1.stepen;i++)
			this->nizkoef[i]=this->nizkoef[i] + p1.nizkoef[i];
		for (int i=0;i<=p2.stepen;i++)
			this->nizkoef[i]=this->nizkoef[i] - p2.nizkoef[i];
	}

}
void Polinom::stampaj()
{
	cout<<"Polinom:"<<endl;
	for (int i=this->stepen;i>1;i--)
		cout<<this->nizkoef[i]<<"X^"<<i<<" + ";
	cout<<this->nizkoef[1]<<"X"<<" + "<<this->nizkoef[0]<<endl;
}
Polinom::~Polinom(void)
{
	delete [] nizkoef;
}

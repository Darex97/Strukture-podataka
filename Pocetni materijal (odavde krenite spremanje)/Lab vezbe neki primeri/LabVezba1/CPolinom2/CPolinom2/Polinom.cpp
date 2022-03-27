#include "Polinom.h"
#include<iostream>
using namespace std;


Polinom::Polinom(int order)
{
	this->stepen=order;
	this->koeficijenti=new double[this->stepen + 1];

	for (int i=0;i<=this->stepen;i++)
		this->koeficijenti[i]=0.0;
}
void Polinom::Koef(int* exp,double* coef,int no)
{
	for (int i=0;i<no;i++)
		this->koeficijenti[exp[i]]=coef[i];
}
void Polinom::stampaj()
{
	cout<<"Polinom:"<<endl;
	for (int i=this->stepen;i>1;i--)
		cout<<this->koeficijenti[i]<<"X^"<<i<<" + ";
	cout<<this->koeficijenti[1]<<"X + ";
	cout<<this->koeficijenti[0]<<endl;
}
Polinom Polinom::oduzmi(const Polinom P)
{
	if (this->stepen >= P.stepen )
	{
		Polinom S(this->stepen);
		for (int i=0;i<=S.stepen;i++)
			S.koeficijenti[i]=this->koeficijenti[i] - P.koeficijenti[i];
		
		return S;
	}

	else
	{
		Polinom S(P.stepen);
		for (int i=0;i<=S.stepen;i++)
			S.koeficijenti[i]=this->koeficijenti[i] - P.koeficijenti[i];

		return S;
	}
}
Polinom::~Polinom()
{
	
}

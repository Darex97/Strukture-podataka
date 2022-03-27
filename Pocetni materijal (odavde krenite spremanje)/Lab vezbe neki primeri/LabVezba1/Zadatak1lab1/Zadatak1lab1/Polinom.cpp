#include "Polinom.h"
#include<iostream>
using namespace std;


Polinom::Polinom(int red)
{
	this->order=red;
	this->niz=new double[order+1];
}

void Polinom::dodaj(int stepen,double koef )
{
	this->niz[stepen]=koef;
}
Polinom& Polinom::saberi(Polinom& P1)
{
	if (this->order > P1.order)
	{
		Polinom P(this->order);
		for (int i=0;i <= P1.order;i++)
		{
			P.niz[i]=this->niz[i] + P1.niz[i];
		}
		for (int i=P1.order+1;i <= this->order ;i++)
			P.niz[i]=this->niz[i];
		return P;
	}
	else
	{
		Polinom P(P1.order);
		for (int i=0;i <= this->order;i++)
		{
			P.niz[i]=this->niz[i] + P1.niz[i];
		}
		for (int i=this->order+1;i <= P1.order;i++)
			P.niz[i]=P1.niz[i];
		return P;
	}
	
	 
}
void Polinom::stampaj()
{
	for (int i=this->order;i>0;i--)
		cout<<this->niz[i]<<"X^"<<i<<" + ";
	cout<<this->niz[0]<<endl;
}
Polinom::Polinom()
{
}
Polinom::~Polinom(void)
{
}

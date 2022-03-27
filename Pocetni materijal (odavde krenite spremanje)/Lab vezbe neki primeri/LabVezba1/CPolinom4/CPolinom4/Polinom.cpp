#include "Polinom.h"
#include<iostream>
using namespace std;


Polinom::Polinom(int red)
{
	this->stepen=red;
	this->nizkoef=new double[stepen+1];
	for (int i=0;i<=this->stepen;i++)
		this->nizkoef[i]=0.0;
}

void Polinom::Coef(int order,double koef )
{
	this->nizkoef[order]=koef;
}
Polinom& Polinom::podeli(Polinom P1,Polinom P2)
{
	if (P1.stepen >= P2.stepen)
	{
		this->stepen=P1.stepen - P2.stepen;
		this->nizkoef= new double[stepen + 1];
		for (int i=0;i<=this->stepen;i++)
			this->nizkoef[i]=0.0;
		int k=0;
		int i=this->stepen;
		int j=P1.stepen;

		while (k <= P1.stepen-P2.stepen)
		{
			this->nizkoef[i]=P1.nizkoef[j]/P2.nizkoef[P2.stepen];
			i--;
			j--;
			k++;
		}

		Polinom S;
		S.pomnozi(*this,P2);

		for (int i=0;i<=P1.stepen;i++)
			P1.nizkoef[i]=P1.nizkoef[i] - S.nizkoef[i];
		
		return P1;
	}
	else
		throw "Polinom je manjeg stepena od delioca.";
}
void Polinom::stampaj()
{
	for (int i=this->stepen;i>0;i--)
		cout<<this->nizkoef[i]<<"X^"<<i<<" + ";
	cout<<this->nizkoef[0]<<endl;
}
void Polinom::pomnozi(Polinom P1,Polinom P2)
{
	this->stepen=P1.stepen + P2.stepen;
		this->nizkoef=new double[stepen + 1];
		for (int i=0;i<=this->stepen;i++)
			this->nizkoef[i]=0;

		for (int i=P1.stepen;i>=0;i--)
			for (int j=P2.stepen;j>=0;j--)
			{
				this->nizkoef[i+j]=this->nizkoef[i+j] + P1.nizkoef[i]*P2.nizkoef[j];
			}
}
Polinom::Polinom()
{
}
Polinom::~Polinom(void)
{
}

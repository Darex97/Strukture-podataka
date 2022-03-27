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
		this->stepen=P1.stepen-P2.stepen;
		this->nizkoef=new double[this->stepen];
		int j=P2.stepen;
		Polinom Proiz(P1.stepen);
		for(int i=this->stepen;i>=0;i--)
		{
			this->nizkoef[i]=P1.nizkoef[P1.stepen]/P2.nizkoef[j];
			for(int l=0;l<=P2.stepen;l++)
			{
				Proiz.nizkoef[l+i]=P2.nizkoef[l]*this->nizkoef[i];
			}
			Proiz.stampaj();
			for(int h=P1.stepen;h>=0;h--)
			{
				P1.nizkoef[h]=P1.nizkoef[h]-Proiz.nizkoef[h];
			}
			P1.stampaj();
			P1.stepen--;
		}

		
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

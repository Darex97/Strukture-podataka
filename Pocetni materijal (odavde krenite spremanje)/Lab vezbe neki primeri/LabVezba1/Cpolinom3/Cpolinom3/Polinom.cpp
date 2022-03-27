#include "Polinom.h"
#include<iostream>
using namespace std;


Polinom::Polinom(int order)
{
	this->stepen=order;
	nizkoef= new double [stepen + 1];
	for (int i=0;i<=stepen;i++)
		nizkoef[i]=0.0;
}
void Polinom::Koef(int* exp,double* coef,int no)
{
	for (int i=0;i<no;i++)
		this->nizkoef[exp[i]]=coef[i];
}
void Polinom::stampaj()
{
	cout<<"Poliom:"<<endl;
	for (int i=this->stepen;i>1;i--)
		cout<<this->nizkoef[i]<<"X^"<<i<<" + ";
	cout<<this->nizkoef[1]<<"X + ";
	cout<<this->nizkoef[0]<<endl;
}
void Polinom::pomnozi(Polinom P1,Polinom P2)
{
	if (this->stepen==-1)
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
}
Polinom::Polinom()
{
	this->stepen=-1;
	this->nizkoef=NULL;
}
Polinom::~Polinom()
{

}

#include "Cpolynom.h"
#include <iostream>
using namespace std;
Cpolynom::Cpolynom()
{
	coef=NULL;
	order=-1;
}
Cpolynom::Cpolynom(int order)
{
	this->order=order;
	coef=new double[order+1];
	for(int i=0;i<=this->order;i++)
			this->coef[i]=0;
}
void Cpolynom::Coef(int exp,double coef)
{
	this->coef[exp]=coef;
}

void Cpolynom::stampaj()
{
	for(int i=this->order;i>0;i--)
	{
		cout<<this->coef[i]<<"x^"<<i<<" + ";
	}
	cout<<this->coef[0]<<endl;
}
Cpolynom::~Cpolynom()
{

}
Cpolynom& Cpolynom::Div(Cpolynom p1,Cpolynom p2)
{
	if(p1.order>=p2.order)
	{
	this->order=p1.order-p2.order;
	this->coef=new double[this->order+1];
	for(int i=0;i<=this->order;i++)
		this->coef[i]=0.0;
	Cpolynom Pr(p1.order);
	int f=this->order;
	int k=p1.order;
	for(int j=0;j<=this->order;j++,k--,f--)
	{
		this->coef[f]=p1.coef[k]/p2.coef[p2.order];

		for(int l=0;l<=p2.order;l++)
			Pr.coef[f+l]=this->coef[f]*p2.coef[l];


		for(int h=k;h>=0;h--)
			p1.coef[h]=p1.coef[h]-Pr.coef[h];
	}
	p1.order=k;
	return p1;
	}
	else
		throw "Nemoguce deljenje zbog stepena";
}

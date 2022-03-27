#include "klase.h"
#include <iostream>
using namespace std;
Lancana_lista::Lancana_lista()
{
	this->koef=0;
	this->exp=0;
	this->sledeci=NULL;
}
Lancana_lista::Lancana_lista(double k,int m)
{
	if(k!=0)
		this->koef=1;
	this->koef=k;
	this->exp=m;
	this->sledeci=NULL;
}
Lancana_lista::~Lancana_lista()
{
	delete this->sledeci;
}
void Lancana_lista::dodaj(double k,int m)
{
	if(k!=0)
		this->koef=1;
		this->koef=k;
		this->exp=m;
}
void Lancana_lista::povezi(Lancana_lista& p)
{
	this->sledeci=&p;
}

CPolynom::CPolynom()
{
	this->broj_clanova=0;
	this->start=new Lancana_lista();
}
CPolynom::~CPolynom()
{
	delete start;
}
void CPolynom::Coef(int exp,double coef)
{
	
	if(this->broj_clanova==0)
	{
		Lancana_lista *x=new Lancana_lista(coef,exp);
		start->povezi(*x);
		this->broj_clanova++;
	}
	else
	{
		Lancana_lista *next;
		next=start->ukazi_na_sledeci();
		Lancana_lista *before;
		before=start;
		int i=0;
		int k=this->broj_clanova;
		while(i<=k)
		{
			if(next->vrati_eksponent()==exp)
			{
				next->dodaj(coef,exp);
			}
			else if(next->ukazi_na_sledeci()!=NULL&&next->vrati_eksponent()>exp)
			{
				before=next;
				next=next->ukazi_na_sledeci();
			}
			else if(next!=NULL&&next->vrati_eksponent()<exp)
			{
				Lancana_lista *x=new Lancana_lista(coef,exp);
				before->povezi(*x);
				x->povezi(*next);
				next=NULL;
				this->broj_clanova++;
			}
			else
			{
				Lancana_lista *x=new Lancana_lista(coef,exp);
				next->povezi(*x);
				next=NULL;
				this->broj_clanova++;
			}
			i++;
			if(next==NULL) break;
		}
	}
}
CPolynom& Add(CPolynom& poly1,CPolynom& poly2)
{
	CPolynom *x=new CPolynom;
	for(int i=0;i<=max(poly1.vrati_stepen(),poly2.vrati_stepen());i++)
	{
		x->Coef(i,poly1.vrati_vrednost(i)+poly2.vrati_vrednost(i));
	}
	return *x;
}
void CPolynom::stampaj()
{
	Lancana_lista *pom;
	pom=start->ukazi_na_sledeci();
	while(pom!=NULL)
	{
		double x=pom->vrati_vrednost();
		if(pom==start->ukazi_na_sledeci()&&pom->vrati_eksponent()>1)
			cout<<x<<"x^"<<pom->vrati_eksponent()<<" ";
		else
		{
			if(pom==start->ukazi_na_sledeci()&&pom->vrati_eksponent()==1)
			{
				cout<<x<<"x";
				goto kraj;
			}
			if(pom==start->ukazi_na_sledeci()&&pom->vrati_eksponent()==0)
			{
				cout<<x;
				goto kraj;
			}
		}
		if(pom->vrati_eksponent()>1&&pom!=start->ukazi_na_sledeci())
		{
			if(x>=0)
				cout<<"+"<<x<<"x^"<<pom->vrati_eksponent();
			else
				cout<<x<<"x^"<<pom->vrati_eksponent();
		}
		if(pom->vrati_eksponent()==1&&pom!=start->ukazi_na_sledeci())
		{
			if(x>=0)
				cout<<"+"<<x<<"x";
			else
				cout<<x<<"x";
		}
		if(pom->vrati_eksponent()==0&&pom!=start->ukazi_na_sledeci())
		{
			if(x>=0)
				cout<<"+"<<x;
			else
				cout<<x;
		}
		kraj:
		cout<<" ";
		pom=pom->ukazi_na_sledeci();
	}
	cout<<endl;
}
double CPolynom::vrati_vrednost(int stepen)
{
	Lancana_lista *x;
	x=start;
	while(x!=NULL&&x->vrati_eksponent()!=stepen)
	{
		x=x->ukazi_na_sledeci();
	}
	if(x==NULL)
		return 0;
	else
		return x->vrati_vrednost();
}
int CPolynom::vrati_stepen()
{
	return start->ukazi_na_sledeci()->vrati_eksponent();	
}

CPolynom& CPolynom::operator=(CPolynom& poly)
{
	this->broj_clanova=poly.broj_clanova;
	this->start=new Lancana_lista;
	Lancana_lista* pom;
	pom=start;
	for(int i=this->broj_clanova-1;i>=0;i--)
	{
		if(poly.vrati_vrednost(i)!=0)
		{
			Lancana_lista* x=new Lancana_lista(poly.vrati_vrednost(i),i);
 			pom->povezi(*x);
			pom=x;
		}
	}
	return *this;
}

#include "PolynomLL.h"
#include<iostream>
using namespace std;


CPolynomLL::CPolynomLL(void)
{
	this->head=NULL;
}
void CPolynomLL::Coef(double c,int e)
{
	if (c!=0)
	{
		SLLNode *novi=new SLLNode(e,c);
		if (this->head==NULL)
		{
			this->head=novi;
		}
		else 
			if(this->head->exp < novi->exp)
			{
				novi->next=head;
				head=novi;
			}
		else
		{
			SLLNode *tmp=head;
			while ( tmp->next!=NULL && novi->exp < tmp->next->exp)
			{
				tmp=tmp->next;
			}
			if (tmp->next == NULL)
			{
				tmp->next=novi;
			}
			else
				{
					novi->next=tmp->next;
					tmp->next=novi;
				}
		}
	}
	else
		throw "Ne pamtimo nulte clanove!";

}
CPolynomLL* CPolynomLL::Mul(CPolynomLL& P1,CPolynomLL& P2)
{
	CPolynomLL pomocni;
	CPolynomLL proizvod;
	CPolynomLL pom_proizvod;
	for (SLLNode *tmp1=P1.head;tmp1!=NULL;tmp1=tmp1->next)
	{
		for (SLLNode *tmp2=P2.head;tmp2!=NULL;tmp2=tmp2->next)
		{
			
			pomocni.Coef(tmp1->coef*tmp2->coef,tmp1->exp+tmp2->exp);

		}
		if (proizvod.head==NULL)
		{
			proizvod.head=pomocni.head;
			pomocni.head=NULL;
		}
		else
		{
			proizvod.head=(pom_proizvod.Add(proizvod,pomocni))->head;
			pomocni.head=NULL;
		}
	}
	this->head=proizvod.head;
	return this;
}
CPolynomLL* CPolynomLL::Add(const CPolynomLL& P1,const CPolynomLL& P2)
{
	if (P1.head != NULL && P2.head != NULL)
	{
		this->head=P1.head;
		SLLNode *tmp;
		for (SLLNode *tmp2=P2.head;tmp2!=NULL;tmp2=tmp2->next)
		{
			tmp=this->head;
			while (tmp->next!=NULL && tmp2->exp!=tmp->exp)
				tmp=tmp->next;
			if (tmp->exp==tmp2->exp)
			{
				tmp->coef=tmp->coef+tmp2->coef;
			}
			else
			{
				this->Coef(tmp2->coef,tmp2->exp);
			}
		}
		return this;
	}
	else
		throw "Polinomi su prazni.";
	
}
void CPolynomLL::PRINT()
{
	
	for (SLLNode *tmp=head;tmp!=NULL;tmp=tmp->next)
		cout<<(*tmp);
	cout<<endl;
}
CPolynomLL::~CPolynomLL(void)
{
}

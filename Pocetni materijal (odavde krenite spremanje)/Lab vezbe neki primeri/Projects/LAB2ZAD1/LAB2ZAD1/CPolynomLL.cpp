#include "CPolynomLL.h"
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

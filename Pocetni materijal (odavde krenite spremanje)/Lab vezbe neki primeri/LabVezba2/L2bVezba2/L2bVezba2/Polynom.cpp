#include "Polynom.h"


CPolynom::CPolynom(void)
{
	this->head=this->tail=NULL;
}
//void CPolynom::AddTodHead(double coef,int exp)
//{
//	this->head=new SLLNode(coef,exp,head);
//}
void CPolynom::AddToTail(double coef,int exp)
{
	if (this->tail!=NULL)
	{
		tail->next=new SLLNode(coef,exp);
		this->tail=this->tail->next;
	}
	else
	{
		this->tail=this->head=new SLLNode(coef,exp);
	}
}
void CPolynom::Add(double coef,int exp)
{
	if (coef!=0)
	{
		SLLNode *novi=new SLLNode(coef,exp);
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
				this->AddToTail(coef,exp);
			}
			else
				{
					novi->next=tmp->next;
					tmp->next=novi;
				}
		}
	}
}
void CPolynom::PRINT()
{
	for (SLLNode *tmp=this->head;tmp!=NULL;tmp=tmp->next)
		cout<<tmp->coef<<"X^"<<tmp->exp<<" ";
	cout<<endl;
}
void CPolynom::Merge(CPolynom *P1,CPolynom *P2)
{
	this->head=P1->head;
	this->tail=P1->tail;
	SLLNode *tmp1;
	for (SLLNode *tmp2=P2->head;tmp2!=NULL;tmp2=tmp2->next)
	{
		tmp1=this->head;
		while (tmp1!=NULL && tmp2->exp!=tmp1->exp)
		{
			tmp1=tmp1->next;
		}
		if (tmp1==NULL)
		{
			this->AddToTail(tmp2->coef,tmp2->exp);
		}
		else
		{
			tmp1->coef=tmp1->coef + tmp2->coef; 
		}
	}
	
}
CPolynom::~CPolynom(void)
{
}

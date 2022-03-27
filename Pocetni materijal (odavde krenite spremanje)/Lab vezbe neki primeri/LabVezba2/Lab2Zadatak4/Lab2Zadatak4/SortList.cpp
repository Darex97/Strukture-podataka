#include "SortList.h"


CSortList::CSortList(void)
{
	this->head=NULL;
}
void CSortList::AddToHead(int num)
{
	this->head=new SLLNode(num,head);
}
void CSortList::PRINT()
{
	for (SLLNode *tmp=this->head;tmp!=NULL;tmp=tmp->next)
		cout<<tmp->number<<" ";
	cout<<endl;
}
void CSortList::SwapNeighbours(SLLNode *tmp,SLLNode *prev)
{
	if (prev== NULL) 
	{
		head = tmp->next;
		tmp->next = tmp->next->next;
		head->next = tmp;
	} 
	else 
	{
		prev->next = tmp->next;
		tmp->next = tmp->next->next;
		prev->next->next = tmp;
	}
}
void CSortList::Swap(SLLNode *tmp1,SLLNode *prev1,SLLNode *tmp2,SLLNode *prev2)
{
	if (tmp1 == tmp2) 
	{
		return;
	} 
	else
	{
			if (tmp1->next == tmp2) 
			{
				SwapNeighbours(tmp1, prev1);
			} 
			else
			{ 
				if (tmp2->next == tmp1) 
				{
					SwapNeighbours(tmp2, prev2);
				} 
				else 
				{
					if (prev1 == NULL)
						head = tmp2;
					else
						prev1->next = tmp2;
					if (prev2 == NULL)
						head = tmp1;
					else
						prev2->next = tmp1;
					SLLNode *tmp= tmp1->next;
					tmp1->next = tmp->next;
					tmp->next = tmp;
				}
			}
	}
}
void CSortList::Sort(bool up)
{
	if (up)
	{
		SLLNode *tmp, *prev;
		SLLNode *tmp1, *prev1, *tmp2, *prev2;
		prev1 = NULL;
		for (tmp1=head; tmp1!=NULL; tmp1=tmp1->next) 
		{
			tmp= tmp1;
			prev= prev1;
			prev2 = tmp1;
			for (tmp2=tmp1->next; tmp2!=NULL; tmp2=tmp2->next) 
			{
				if (tmp->number > tmp2->number) 
				{
					tmp= tmp2;
					prev= prev2;
				}
				prev2 = tmp2;
			}
			if (tmp1 != tmp) 
			{
				Swap(tmp1, prev1, tmp, prev);
				tmp1 = tmp;
			}
			prev1 = tmp1;
		}
	}
	else
	{
		SLLNode *tmp, *prev;
		SLLNode *tmp1, *prev1, *tmp2, *prev2;
		prev1 = NULL;
		for (tmp1=head; tmp1!=NULL; tmp1=tmp1->next) 
		{
			tmp= tmp1;
			prev= prev1;
			prev2 = tmp1;
			for (tmp2=tmp1->next; tmp2!=NULL; tmp2=tmp2->next) 
			{
				if (tmp->number < tmp2->number) 
				{
					tmp= tmp2;
					prev= prev2;
				}
				prev2 = tmp2;
			}
			if (tmp1 != tmp) 
			{
				Swap(tmp1, prev1, tmp, prev);
				tmp1 = tmp;
			}
			prev1 = tmp1;
		}
	}
}
CSortList::~CSortList(void)
{
}

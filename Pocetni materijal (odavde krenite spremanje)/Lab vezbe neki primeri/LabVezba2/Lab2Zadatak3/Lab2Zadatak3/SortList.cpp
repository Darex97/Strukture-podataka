#include "SortList.h"


CSortList::CSortList(void)
{
	this->head=this->tail=NULL;
}
void CSortList::AddToHead(int number)
{
	head=new SLLNode(number,this->head);
	if (this->tail==NULL)
		this->tail=this->head;
}
void CSortList::SwapNeighbours(SLLNode *tmp2,SLLNode *prev2)
{
	
	if (prev2== NULL) 
	{
		head = tmp2->next;
		tmp2->next = tmp2->next->next;
		head->next = tmp2;
	} 
	else 
	{
		prev2->next = tmp2->next;
		tmp2->next = tmp2->next->next;
		prev2->next->next = tmp2;
	}
}
void CSortList::Sort(bool up)
{
	if (up)
	{
		SLLNode *tmp1;	
		SLLNode *tmp2, *prev2;
		for (tmp1=tail; tmp1!=head; tmp1=prev2) 
		{
			prev2 = NULL;
			for (tmp2=head; tmp2->next!=tmp1; ) 
			{
				if (tmp2->number > tmp2->next->number) 
				{
					SwapNeighbours(tmp2, prev2);
					if (prev2 != NULL) 
					{
						prev2 = prev2->next;
					} 
					else
					{
						prev2 = head;
					}
				} 
				else 
				{
					prev2 = tmp2;
					tmp2=tmp2->next;
				}
			}
			if (tmp2->number > tmp2->next->number) 
			{
				SwapNeighbours(tmp2, prev2);
				if (prev2 != NULL) 
				{
					prev2 = prev2->next;
				} 
				else 
				{
					prev2 = head;
				}
			} 
			else 
			{
				prev2 = tmp2;
			}
		}
	}

	else
	{
		SLLNode *tmp1;	
		SLLNode *tmp2, *prev2;
		for (tmp1=tail; tmp1!=head; tmp1=prev2) 
		{
			prev2 = NULL;
			for (tmp2=head; tmp2->next!=tmp1; ) 
			{
				if (tmp2->number < tmp2->next->number) 
				{
					SwapNeighbours(tmp2, prev2);
					if (prev2 != NULL) 
					{
						prev2 = prev2->next;
					} 
					else
					{
						prev2 = head;
					}
				} 
				else 
				{
					prev2 = tmp2;
					tmp2=tmp2->next;
				}
			}
			if (tmp2->number < tmp2->next->number) 
			{
				SwapNeighbours(tmp2, prev2);
				if (prev2 != NULL) 
				{
					prev2 = prev2->next;
				} 
				else 
				{
					prev2 = head;
				}
			} 
			else 
			{
				prev2 = tmp2;
			}
		}
	}
}
void CSortList::PRINT()
{
	for (SLLNode *tmp=this->head;tmp!=NULL;tmp=tmp->next)
		cout<<tmp->number<<" ";
	cout<<endl;
}
CSortList::~CSortList(void)
{
}

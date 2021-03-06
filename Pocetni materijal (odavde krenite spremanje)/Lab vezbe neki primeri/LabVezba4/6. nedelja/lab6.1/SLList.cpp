#include "SLList.h"
#include <iostream.h>

SLList::SLList()
{
	head=tail=0;
}

SLList::~SLList()
{
}

void SLList::AddToHead(HashObject k)
{
	if (head==0)
		head=tail=new SLLNode(k);
	else
	{
		SLLNode *t =new SLLNode(k);
		tmp->link=head;
		head=tmp;
	}
}

void SLList::Print()
{
	for (SLLNode *tmp=head;tmp!=0;tmp=tmp->link)
	{
		cout<<"|";
		tmp->info.Print();
		cout<<"| -> ";
	}
}
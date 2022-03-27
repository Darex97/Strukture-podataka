#include "DequeueAsLList.h"

DequeueAsLList::DequeueAsLList()
{
	head=tail=NULL;
}
void DequeueAsLList::enqueuehead(int x)
{
	if(!IsEmpty())
	{
		head=new Node(x,NULL,head);
		head->getnext()->setprev(head);
	}
	else
		head=tail=new Node(x,NULL,NULL);
}

void DequeueAsLList::enqueuetail(int x)
{
	if(!IsEmpty())
	{
		tail->setnext(new Node(x,tail,NULL));
		tail=tail->getnext();
	}
	else
		head=tail=new Node(x,NULL,NULL);
}

int DequeueAsLList::dequeuehead()
{
	if(IsEmpty())
		throw "Red je prazan";
	int rez=head->getinfo();
	Node* tmp=head;
	if(head==tail)
		head=tail=NULL;
	else
		head=head->getnext();
	delete tmp;
	return rez;
}
int DequeueAsLList::dequeuetail()
{
	if(!IsEmpty())
	{
		int rez=tail->getinfo();
		Node* tmp=tail;
		if(head==tail)
			head=tail=NULL;
		else
		{
			tail=tail->getprev();
			tail->setnext(NULL);
		}
		delete tmp;
		return rez;
	}
	else
		throw "Red je prazan";
}
void DequeueAsLList::stampaj()
{
	for(Node* tmp=head;tmp!=NULL;tmp=tmp->getnext())
		tmp->print();
	cout<<endl<<"/////"<<endl;
}
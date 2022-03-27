#include "DequeueAsList.h"


DequeueAsList::DequeueAsList(void)
{
	this->head=this->tail=NULL;
}
bool DequeueAsList::isEmpty()
{
	if (this->head==NULL)
		return true;
	else
		return false;
}
void DequeueAsList::enqueueHead(int number)
{
	if (this->isEmpty())
	{
		this->head=this->tail=new Node(number,NULL,NULL);
	}
	else
	{
		head=new Node(number,NULL,head);
		head->next->previous=head;
	}
}
int DequeueAsList::dequeueHead()//? proveriti da li prev postaje NULL
{
	if (!this->isEmpty())
	{
		Node *tmp=this->head;
		int s=tmp->number;
		if (this->head==this->tail)
			this->head=this->tail=NULL;
		else
		{
			this->head=this->head->next;
		}
		delete tmp;
		return s;
	}
	else
		throw "Izuzetak:Red je prazan,ne moze se nista vise iskljuciti.";
}
void DequeueAsList::enqueueTail(int number)
{
	if (this->isEmpty())
	{
		this->head=this->tail=new Node(number,NULL,NULL);
	}
	else
	{
		tail=new Node(number,tail,NULL);
		tail->previous->next=tail;
	}
}
int DequeueAsList::dequeueTail()//?
{
	if (!this->isEmpty())
	{
		Node *tmp=this->tail;
		int s=tail->number;
		if (this->head==this->tail)
			this->head=this->tail=NULL;
		else
		{
			tail=tail->previous;
			tail->next->previous=NULL;
			tail->next=NULL;
		}
		delete tmp;
		return s;
	}
	else
		throw "Izuzetak:Red je prazan,ne moze se nista vise iskljuciti.";
}
void DequeueAsList::PRINT()
{
	for (Node *tmp=this->head;tmp!=NULL;tmp=tmp->next)
		cout<<tmp->number<<" ";
	cout<<endl;
}
DequeueAsList::~DequeueAsList(void)
{
}

#include "QueueAsList.h"


QueueAsList::QueueAsList(void)
{
	this->head=this->tail=NULL;
}
bool QueueAsList::isEmpty()
{
	if (this->head==NULL)
		return true; 
	else
		return false;
}
void QueueAsList::enqueue(int number)
{
	if (!this->isEmpty())
	{
		this->tail->next=new Node(number);
		this->tail=this->tail->next;
	}
	else
		this->head=this->tail=new Node(number);
}
int QueueAsList::dequeue()
{
	if (!this->isEmpty())
	{
		Node *tmp=this->head;
		int s=this->head->number;
		if (this->head==this->tail)
			this->head=this->tail=NULL;
		else
			this->head=this->head->next;
		delete tmp;
		return s;
	}
	else
		throw "Izuzetak:Red je prazan.";
}
Node QueueAsList::getHead()
{
	if (!this->isEmpty())
	{
		Node *tmp=this->head;
		return *tmp;
	}
	else
		throw "Izuzetak:Red je prazan.";
}
int QueueAsList::numberOfElements()
{
	int result=0;
	if (!this->isEmpty())
	{
		Node *tmp=this->head;
		while (tmp!=NULL)
		{
				tmp=tmp->next;
				result++;
		}
		return result;
	}
	else
		return result;
}
void QueueAsList::PRINT()
{
	if (!this->isEmpty())
	{
		for (Node *tmp=this->head;tmp!=NULL;tmp=tmp->next)
			cout<<tmp->number<<" ";
		cout<<endl;
	}
	else
		throw "Izuzetak:Red je prazan.";
}
QueueAsList::~QueueAsList()
{
}

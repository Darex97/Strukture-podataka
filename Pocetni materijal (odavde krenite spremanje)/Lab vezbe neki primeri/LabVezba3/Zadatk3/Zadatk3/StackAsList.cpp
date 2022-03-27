#include "StackAsList.h"


StackAsList::StackAsList(void)
{
	this->top=NULL;
}
bool StackAsList::isEmpty()
{
	if (this->top==NULL)
		return true;
	else
		return false;
}
void StackAsList::push(int number)
{
	top=new Node(number,top);
}
Node StackAsList::pop()
{
	if (this->isEmpty())
		throw "Izuzetak:Stek je prazan.";
	else
	{
		Node *tmp=this->top;
		this->top=this->top->next;
		return *tmp;
	}
}
Node StackAsList::getTop()
{
	if (this->isEmpty())
		throw "Izuzetak:Stek je prazan.";
	else
	{
		return *this->top;
	}
}
void StackAsList::PRINT()
{
	cout<<"Trenutno stanje steka:"<<endl;
	if (this->top==NULL)
		throw "Stek je prazan.";
	else
	{
		for (Node *tmp=this->top;tmp!=NULL;tmp=tmp->next)
			cout<<tmp->number<<" ";
		cout<<endl;
	}
}
StackAsList::~StackAsList(void)
{
}

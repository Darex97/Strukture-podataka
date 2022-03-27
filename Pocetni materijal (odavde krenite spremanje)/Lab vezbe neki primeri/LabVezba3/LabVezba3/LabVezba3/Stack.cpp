#include "Stack.h"


Stack::Stack(int size)
{
	this->size=size;
	this->_array=new int[size];
	this->top=-1;
}
void Stack::push(int number)
{
	if (this->top==this->size-1)
		throw "Izuzetak:Stek je pun.";
	else
	{
		this->_array[++top]=number;
	}
}
int Stack::pop()
{
	if (this->top==-1)
		throw "Stek je prazan.";
	else
	{
		int tmp=this->_array[top--];
		return tmp;
	}
}
Stack::~Stack(void)
{
	delete []this->_array;
}

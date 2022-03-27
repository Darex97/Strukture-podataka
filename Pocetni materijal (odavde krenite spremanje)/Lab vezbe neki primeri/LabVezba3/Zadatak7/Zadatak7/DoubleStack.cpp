#include "DoubleStack.h"


DoubleStack::DoubleStack(void)
{
}
DoubleStack::DoubleStack(int size)
{
	this->size=size;
	this->_array=new int[this->size];
	this->top1=-1;
	this->top2=this->size;
}
bool DoubleStack::isEmpty()
{
	if (this->top1==-1 && this->top2==size)
		return true;
	else
		return false;
}
bool DoubleStack::isFull()
{
	if (this->top2==(this->top1+1))
		return true;
	else
		return false;
}
void DoubleStack::push(int number,bool s)
{
	if (!this->isFull())
	{
		if (s)
		{
			this->top1=this->top1+1;
			this->_array[this->top1]=number;
		}
		else
		{
			this->_array[--this->top2]=number;
		}
	}
	else
		throw "Izuzetak:Stek je pun.";
}
int DoubleStack::pop(bool s)
{
	if (!this->isEmpty())
	{
		int tmp;
		if (s)
		{
			if (this->top1>-1)
				tmp=this->_array[top1--];
			else
				throw "Izuzetak:Prvi stek je prazan.";
		}
		else
		{
			if (this->top2<this->size)
				tmp=this->_array[top2++];
			else
				throw "Izuzetak:Drugi stek je prazan.";
		}
		return tmp;
	}
	else
		throw "Izuzetak:Stek je prazan.";
}
int DoubleStack::numOfElements()
{
	return this->size-this->top2+this->top1+1;
}
void DoubleStack::print()
{
	if (!this->isEmpty())
	{
		cout<<"Prvi deo steka:"<<endl;
		for (int i=0;i<=this->top1;i++)
			cout<<this->_array[i]<<" ";
		cout<<endl;
		
		cout<<"Drugi deo steka:"<<endl;
		for (int i=size-1;i>=this->top2;i--)
			cout<<this->_array[i]<<" ";
		cout<<endl;
	}
	else
		throw "Izuzetak:Stek se ne moze stampati,prazan je.";
}
DoubleStack::~DoubleStack(void)
{
	/*delete []this->_array;*/
}

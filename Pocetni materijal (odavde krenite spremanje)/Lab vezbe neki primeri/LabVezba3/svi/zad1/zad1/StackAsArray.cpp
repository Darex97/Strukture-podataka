#include "StackAsArray.h"
#include <iostream>
using namespace std;
StackAsArray::StackAsArray( int n)
	:QueueAsArray(n)
{
}
void StackAsArray::push(int x)
{
	this->enqueue(x);
}
int StackAsArray::pop()
{
	if(this->IsEmpty())
		throw "Potkoracenje";
	int rezultat=niz[tail--];
	return rezultat;
}
void StackAsArray::stampaj()
{
	int tmp=tail;
	while(!this->IsEmpty())
	{
		cout<<this->gettop()<<endl;
		tail--;
	}
	tail=tmp;
	cout<<"//////"<<endl;
}
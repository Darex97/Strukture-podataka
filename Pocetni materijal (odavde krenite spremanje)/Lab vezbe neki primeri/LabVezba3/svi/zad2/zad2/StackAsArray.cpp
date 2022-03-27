#include "StackAsArray.h"

StackAsArray::StackAsArray(int x)
	:Dequeue(x)
{
}
StackAsArray::~StackAsArray(){}
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
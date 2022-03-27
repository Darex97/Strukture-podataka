#include "HashTable.h"
#include <iostream.h>

int HashTable::h(HashObject obj)
{
	return (f(obj.GetKey())%this->length);
}


int HashTable::f(char* s)
{
	int res=0;
	int a=7;
	for (int i=0;s[i]!=0;i++)
		res=res<<a^s[i];
	return res;
}

/*int HashTable::g(int i)
{
}*/

HashTable::HashTable(int l)
{
	this->length=l;
	count=0;
	array=new SLList[this->length];
}

HashTable::~HashTable()
{
}

void HashTable::Insert(HashObject obj)
{
	array[h(obj)].AddToHead(obj);
	count++;
}

void HashTable::WithDraw(HashObject obj)
{
}

void HashTable::Print()
{
	for (int i=0;i<length;i++)
	{
		cout<<i<<" --> ";
		array[i].Print();
		cout<<endl;
	}
}
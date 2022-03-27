#include "ChainedHashTable.h"
#include<cmath>


ChainedHashTable::ChainedHashTable(int length)
{
	this->length=length;
	this->count=0;
	this->array=new SLList[this->length];
}
void ChainedHashTable::insert(HashObject obj)
{
	this->array[h(obj)].addToHead(obj.getKey(),obj.getRecord());
	this->count++;
}
int ChainedHashTable::h(HashObject obj)//odredjuje index,poziva odgovarajuce f-je u zavisnosti od kljuca
{
	return (f(obj.getKey()) % this->length);
}
int ChainedHashTable::f(int k)
{
	return abs(k);
}
int ChainedHashTable::f(char *s)
{
	int result=0;
	int a=7;
	for(int i=0;s[i]!=0;i++)
		result=result<<a^s[i];
	return result;
}
void ChainedHashTable::display()
{
	for(int i=0;i<this->length;i++)
	{
		cout<<"["<<i<<"]"<<"->"<<" ";
		HashObject *tmp=this->array[i].head;
		while(tmp!=NULL)
		{
			tmp->print();
			tmp=tmp->next;
		}
		cout<<endl;
	}
	cout<<endl;
}
ChainedHashTable::~ChainedHashTable(void)
{
}

#include "ChainedHashTable.h"


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
int ChainedHashTable::h(HashObject obj)
{
	return (obj.getKey()%1000);
}
void ChainedHashTable::display()
{
	for(int i=0;i<400;i++)
	{
		HashObject *tmp=this->array[i].head;
		cout<<"["<<i<<"]"<<"->";
		while(tmp!=NULL)
		{
			tmp->print();
			tmp=tmp->synonym;
		}
		cout<<endl;
	}
}
ChainedHashTable::~ChainedHashTable(void)
{
}

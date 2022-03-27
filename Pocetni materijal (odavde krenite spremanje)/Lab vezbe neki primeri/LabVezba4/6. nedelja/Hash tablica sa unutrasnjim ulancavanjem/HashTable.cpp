#include "HashTable.h"
#include <iostream.h>
#include <math.h>


HashTable::HashTable(unsigned int len)
{
	length=len;
	count=0;
	array=new HashObject[len];
	for (unsigned int i=0;i<len;i++)
		array[i]=HashObject();
}


HashTable::~HashTable()
{
	for (unsigned int i=0;i<length;i++)
		array[i].DeleteRecord();
	delete [] array;
}


void HashTable::Display()
{
	for (unsigned int i=0;i<length;i++)
		if (!array[i].free)
		{
			cout<<"["<<i<<"]"<<" |";
			array[i].Print();
			cout<<"|"<<array[i].next<<endl;
		}
		else
			cout<<"["<<i<<"]"<<endl;
}


void HashTable::Insert(HashObject obj)
{
	if (count==this->GetLength())
		throw Exception::FULL;
	else
	{
		long probe=this->h(obj);
		if (!array[probe].free)
		{
			while(array[probe].next!=-1)
				probe=array[probe].next;

			long tail=probe;
			probe=g(probe);
			while(!array[probe].free && probe!=tail)
				probe=g(probe);
			if (probe==tail)
				throw Exception::POOR;
			array[tail].next=probe;
		}

		array[probe]=obj;
		array[probe].free=false;
		array[probe].next=-1;
		count++;
	}
}


HashObject HashTable::Find(char* key)
{
	long probe=f(key)%length;
	while(!array[probe].IsEqualKey(key) && array[probe].next!=-1)
			probe=array[probe].next;
	if (array[probe].IsEqualKey(key))
		return array[probe];
	else
		throw Exception::NOT;
}


void HashTable::Withdraw (char* key)
{
	if (count == 0) 
		throw Exception::EMPTY;
	long probe = f(key)%length;
	long prev = -1;
	while (probe != -1 && !array[probe].IsEqualKey(key))
	{
		prev = probe;
		probe = array [probe].next;
	}
	if (probe == -1) 
		throw Exception::NOT;
	if( prev != -1)
	{
 
		array[prev].next = array[probe].next; 
		array[probe].DeleteRecord(); 
		array[probe].free = true;

	}
	else
	{
		if(array[probe].next == -1)
		{
			array[probe].DeleteRecord(); 
			array[probe].free = true;
		}
		else
		{
			long nextEl = array[probe].next; 
			array[probe].DeleteRecord(); 
			array[probe] = array[nextEl]; 
			array[probe].next = array[nextEl].next;
			array[nextEl] = HashObject();
			array[nextEl].free = true;

		}


	}
	count--;

}


unsigned int HashTable::h(HashObject obj)
{
	return (f(obj.GetKey())%length);
}

	
unsigned int HashTable::f(char* s)
{
	unsigned int res=0;
	unsigned int a=7;
	for (int i=0;s[i]!=0;i++)
		res=res<<a^s[i];
	return res;
}

	
unsigned int HashTable::g(unsigned int i)
{
	return (i+1)%length;
}

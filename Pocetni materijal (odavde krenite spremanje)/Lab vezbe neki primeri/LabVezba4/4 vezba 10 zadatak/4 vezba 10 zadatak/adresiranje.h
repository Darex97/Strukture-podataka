#pragma once
#include"element.h"
#include"tablica.h"
#include<iostream>
using namespace std;
template <class T, class R>
class adresiranje : public tablica<T, R>  
{
protected:
	element<T, R> *array;
public:
	adresiranje(unsigned int len)
	{
		length = len;
		count = 0;
		array=new element<T,R>[len];
		for (unsigned int i=0; i<len; i++)
		{
			array[i] = element<T,R>();
			array[i].free = true;
		}
	}
	virtual ~adresiranje()
	{
		for (unsigned int i=0; i<length; i++)
			array[i].deleteRecord();
		delete [] array;
	}
	unsigned int findUnoccupied(element<T, R> obj)
	{
		unsigned int hash = h(obj);
		unsigned int probe = hash;
		unsigned int k = 0;
		do
		{
			if (array[probe].free) return probe;
			k++;
			probe = g(hash);
		}
		while(probe != hash);
		throw "tabla je puna";
	}
	long findMatch(T key)
	{
		unsigned int hash = f(key)%length;
		unsigned int probe = hash;
		for (unsigned int i=0; i<length; i++)
		{
			if (array[probe].free) return -1;
			if (array[probe].isEqualKey(key)) return probe;
			probe = g(hash, i);
		}
		return -1;
	}
	void insert(element<T, R> obj)
	{
		if (count == length)
			throw "tabla je puna";
		unsigned int offset = findUnoccupied(obj);
		array[offset] = obj;
		array[offset].free = false;
		count++;
	}
	void display()
	{
		for(unsigned int i=0;i<length;i++)
			if(!array[i].free)
			{
				cout<<"["<<i<<"]"<<"|";
				array[i].print();
				cout<<endl;
			}
			else
			{
				cout<<"["<<i<<"]"<<endl;
			}
	}

	/*ScatterObject<T, R> find (T key)
	{
		long offset = findMatch(key);
		if (offset >= 0)
			return array[offset];
		throw "element not found\n";
	}

	void withdraw(T key)
	{
		if (count == 0)
			throw "table is empty";
		long offset = findMatch(key);
		if (offset < 0)
			throw "object not found";
		array[offset].free = true;
		array[offset].deleteRecord();
		count--;
	}*/
};

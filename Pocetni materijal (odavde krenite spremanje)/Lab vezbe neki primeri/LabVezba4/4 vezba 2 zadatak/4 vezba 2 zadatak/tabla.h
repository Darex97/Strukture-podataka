#pragma once
#include "tablica.h"
#include "lista.h"

template <class T, class R>
class tabla : public tablica<T,R>
{
protected:
	lista<element<T,R> > *array;
public:
	void printTable()
	{
		for(unsigned int i=0; i<length; i++)
		{
			array[i].PrintAll();
		}
	}
	tabla(unsigned int len)
	{
		length=len;
		count=0;
		array=new lista<element<T,R>>[len];
	}
	void insert(element<T,R> obj)
	{
		array[h(obj)].addToHead(obj);
		count++;
	}
	void withdraw(element<T,R> obj)
	{
		array[h(obj)].deleteEl(obj);
		count--;
	}
	void withdraw(T key)
	{
		element<T,R> obj=find(key);
		withdraw(obj);
	}
	element<T,R> find(T key)
	{
		element<T,R> obj;
		unsigned int i=f(key)%length;
		obj=array[i].getHeadEl();
		while(!(obj.isEqualKey(key)))
			obj=array[i].getNextEl(obj);
		return obj;
	}
	void display()
	{
		//tablica<T,R> pom;
		
		for(unsigned int i=0; i<length; i++)
		{
			cout << "[" << i << "]" << "X->";

			element<T,R> obj;
			try
			{
				obj = array[i].getHead();
				while(true)
				{
					obj.print();
					cout<<"->";
					obj = array[i].getNext(obj);
				}
			}
			catch(char *izuzetak)
			{
				cout <<izuzetak<<endl;
			}
		}
	}
};
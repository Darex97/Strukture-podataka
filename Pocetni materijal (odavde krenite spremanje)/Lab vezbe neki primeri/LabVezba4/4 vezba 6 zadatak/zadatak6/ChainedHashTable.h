#pragma once
#include "DLList.h"
#include "hashtable.h"
using namespace std;

template <class T, class R>
class ChainedHashTable :
	public HashTable<T,R>
{
protected:
	DLList<HashObject<T,R>> *niz;
public:

	ChainedHashTable(int len);
	virtual ~ChainedHashTable(void);
	void display();
	void insert(HashObject<T,R> obj);
	void withdraw(HashObject<T,R> obj);
	void withdraw(T key);
//	HashObject<T,R> find(T key);


};
template <class T, class R>
ChainedHashTable<T,R>::ChainedHashTable(int len)
{
	this->lenght=len;
	count=0;
	niz=new DLList<HashObject<T,R>>[len];
}
template <class T, class R>
ChainedHashTable<T,R>::~ChainedHashTable()
{
	HashObject<T,R> obj;
	for(int i=0;i<this->lenght;i++)
	{
		try{
			obj=niz[i].getHeadEl();
			while(true)
			{
				obj.deleteRecord();
				obj=niz[i].getNextEl(obj);
			}
		}
			catch(...)
			{
				cout << endl;
			}
		}
		delete[] niz;
}


template <class T, class R>
void ChainedHashTable<T,R>::display()
{
	for(int i=0;i<this->lenght;i++)
	{
		cout << "[" << i << "]" << "X->";
		HashObject<T,R> obj;
		try
		{
			obj=niz[i].getHeadEl();
			while(true)
			{
				obj.print();
				cout << "->";
				obj=niz[i].getNextEl(obj);
			}
		}
		catch(...)
		{
			cout << endl;
		}
	}
}
template <class T, class R>
void ChainedHashTable<T,R>::insert(HashObject<T,R> obj)
{
	this->niz[this->h(obj)].addToHead(obj);
	this->count++;
}
template <class T, class R>
void ChainedHashTable<T,R>::withdraw(HashObject<T,R> obj)
{
	niz[h(obj)].deleteEl(obj);
	this->count--;
}
template <class T, class R>
void ChainedHashTable<T,R>::withdraw(T key)
{
	HashObject<T,R> obj;
	int i=f(key)%lenght;
	obj=niz[i].getHeadEl();
	while(!(obj.isEqualKey(key)))
		obj=niz[i].getNextEl(obj);
	return obj;
}
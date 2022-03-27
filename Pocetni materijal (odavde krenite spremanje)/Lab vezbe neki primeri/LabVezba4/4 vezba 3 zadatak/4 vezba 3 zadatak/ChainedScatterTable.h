#pragma once
#include"HashObject.h"
#include"ChainedScatterObject.h"
#include<iostream>
#include <cmath>
#include "HashTable.h"
using namespace std;
template<class Tkey,class Tobj>
class ChainedScatterTable:public HashTable<Tkey,Tobj>
{
protected:
	ChainedScatterObject<Tkey,Tobj> *array;
public:
	ChainedScatterTable(int len)
	{
		lenght=len;
		count=0;
		array=new ChainedScatterObject<Tkey,Tobj>[lenght];
		for(int i=0;i<lenght;i++)
		{
			array[i]=ChainedScatterObject<Tkey,Tobj>();
			array[i].free=true;
			array[i].next=-1;
		}
	}
	~ChainedScatterTable()
	{
		for(int i=0;i<lenght;i++)
			array[i].deleteRecord();
		delete [] array;
	}
	void display()
	{
		for(int i=0;i<lenght;i++)
		{
			if(!array[i].free)
			{
				cout<<"["<<i<<"]"<<"|";
				array[i].print();
				cout<<"|"<<array[i].next<<endl;
			}
			else
				cout<<"["<<i<<"]"<<endl;
		}
	}
	void insert(ChainedScatterObject<Tkey,Tobj> obj)
	{
		if(count==getLength())
			throw "The table is full!";
		long probe=h(obj);
		if(!array[probe].free)
		{
			while(array[probe].next!=-1)
			{
				probe=array[probe].next;
			}
			long tail=probe;
			probe=g(probe);
			while(!array[probe].free && probe!=tail)
				probe=g(probe);
			if(probe==tail)
				throw "Poor secondary transformation!";
			array[tail].next=probe;
		}
		array[probe]=obj;
		array[probe].free=false;
		array[probe].next=-1;
		count++;
	}
	ChainedScatterObject<Tkey,Tobj> find(Tkey key)
	{
		long probe=f(key)%lenght;
		while(probe!=-1)
		{
			if(!array[probe].isEqualKey(key))
				probe=g(probe);
			return array[probe];
		}
		throw "Element not found!";
	}
	void withdraw(Tkey key)
	{
		if(count==0)
			throw "Table is empty!";
		long probe=f(key)%lenght;
		long prev=-1;
		while(probe!=-1 && !array[probe].isEqualKey(key))
		{
			prev=probe;
			probe=array[probe].next;
		}
		if(probe==-1)
			throw "Element not found!";
		if(prev!=-1)
		{
			array[prev].next=array[probe].next;
			array[probe].deleteRecord();
			array[probe].free=true;
		}
		else
		{
			if(array[probe].next==-1)
			{
				array[probe].deleteRecord();
				array[probe].free=true;
			}
			else
			{
				long nextEl=array[probe].next;
				array[probe].deleteRecord();
				array[probe]=array[nextEl];
				array[probe].next=array[nextEl].next;
				array[nextEl]=ChainedScatterObject<Tkey,Tobj>();
				array[nextEl].free=true;
			}
		}
		count--;
	}
};

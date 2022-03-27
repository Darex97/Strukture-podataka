#pragma once
#include"element.h"
#include"ulancavanje.h"
#include<iostream>
#include <cmath>
#include "tablica.h"
using namespace std;
template<class Tkey,class Tobj>
class rasutatablica:public tablica<Tkey,Tobj>
{
protected:
	ulancavanje<Tkey,Tobj> *array;
public:
	rasutatablica(int len)
	{
		lenght=len;
		count=0;
		array=new ulancavanje<Tkey,Tobj>[lenght];
		for(int i=0;i<lenght;i++)
		{
			array[i]=ulancavanje<Tkey,Tobj>();
			array[i].free=true;
			array[i].next=-1;
		}
	}
	~rasutatablica()
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
	void insert(ulancavanje<Tkey,Tobj> obj) 
	{
		if(count==getLength())
			throw "The table is full!";
		long probe=h(obj);
		long gp=probe;
		bool prvi=false;
		if(array[probe].free)
		{
			array[probe]=obj;
			array[probe].free=false;
			array[probe].next=-1;
		}
		else
		{
			long pred=probe;
			probe=7;
			if(array[probe].free)
			{
				array[pred].next=probe;
				array[probe]=obj;
				array[probe].free=false;
				array[probe].next=-1;
				count++;
				return;
			}
			else
				while(h(array[probe].key)!=pred) 
				{
					if(array[probe+1].free) 
					{
						++probe;
						prvi=true;
						break;
					}
					probe++;
				}

				if(!array[probe].free)
				{
				while(array[probe].next!=-1)
				{
					probe=array[probe].next;
				}
				long tail=probe;
				while(!array[probe].free && probe!=lenght)
					++probe;
				
				if(probe==tail)
					throw "Losa sekundarna transformacija!";
				array[tail].next=probe;
				}
		if(prvi)
			array[gp].next=probe;
		array[probe]=obj;
		array[probe].free=false;
		array[probe].next=-1;
		count++;
		}
	}
	ulancavanje<Tkey,Tobj> find(Tkey key)
	{
		long probe=f(key)%lenght;
		while(probe!=-1)
		{
			if(!array[probe].isEqualKey(key))
				probe=g(probe);
			return array[probe];
		}
		throw "Element nije pronadjen!";
	}
	void withdraw(Tkey key)
	{
		if(count==0)
			throw "Tablica je prazna!";
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
				array[nextEl]=ulancavanje<Tkey,Tobj>();
				array[nextEl].free=true;
			}
		}
		count--;
	}
};

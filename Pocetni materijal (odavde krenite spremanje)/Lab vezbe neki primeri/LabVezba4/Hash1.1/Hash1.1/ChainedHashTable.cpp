#include "ChainedHashTable.h"
#include <cmath>
using namespace std;
int ChainedHashTable::f(int k)//ako je kljuc ceo broj
{
	return abs(k);
}
int ChainedHashTable::f(char* s)//ako je kluc tipa string
{
	int res=0;
	int a=7;
	for(int i=0;s[i]!=0;i++)
		res=res<<a^s[i];
	return res;
}
int ChainedHashTable::h(HashObject o)//na osnovu kljuca zadaje index u tablicu
{
	return (this->f(o.getrecord())%n);
}
ChainedHashTable::ChainedHashTable(int x)
{
	this->n=x;
	this->t=0;
	this->array=new SLList[n];
}
ChainedHashTable::~ChainedHashTable()
{
	SLList *l;
	for(int i=0;i<n;i++)
	{
		l=&array[i];
		while(!l->IsEmpty())
			l->deletefromhead();
	}
	delete [] array;
}
void ChainedHashTable::insert(HashObject& obj)
{
	array[h(obj)].addtohead(h(obj),obj.getrecord());
	this->t++;
}
void ChainedHashTable::withdraw(HashObject obj)
{
	array[h(obj)].deleteEl(obj.getrecord());
	this->t--;
}

HashObject ChainedHashTable::find(int ky)
{
	HashObject *tmp=array[ky].gethead();
	while(tmp!=NULL && tmp->getkey()!=ky)
		tmp=tmp->getnext();
	if(tmp!=NULL)
		return *tmp;
	else
	{
		cout<<"Nema objekta sa takvim kljucem u tablici."<<endl;
		return *tmp;
	}
}
void ChainedHashTable::display()
{
	for(int i=0;i<this->n;i++)
	{
		cout<<"["<<i<<"]"<<"-> ";
		HashObject *tmp=array[i].gethead();
		while(tmp)
		{
			tmp->print();
			tmp=tmp->getnext();
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
}
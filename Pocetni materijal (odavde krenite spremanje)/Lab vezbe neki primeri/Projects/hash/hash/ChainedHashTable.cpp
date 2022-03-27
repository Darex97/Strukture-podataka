#include "ChainedHashTable.h"
#include <cmath>
using namespace std;

int ChainedHashTable::f(int k)
{
	return abs(k);
}
int ChainedHashTable::f(char* s)
{
	int res = 0;
	int a = 7;
	for (int i = 0; s[i] != 0; i++)
		res = res << a^s[i];
	return res;
}
int ChainedHashTable::h(HashObject o)
{
	return (this->f(o.getrecord()) % this->length);
}
ChainedHashTable::ChainedHashTable(int length)
{
	this->length = length;
	this->numOfElements = 0;
	this->array = new SLList[this->length];
}
ChainedHashTable::~ChainedHashTable()
{
	SLList *l;
	for (int i = 0; i<this->length; i++)
	{
		l = &array[i];
		while (!l->IsEmpty())
			l->deletefromhead();
	}
	delete[] array;
}
void ChainedHashTable::insert(HashObject& obj)
{
	array[h(obj)].addtohead(h(obj), obj.getrecord());
	this->numOfElements++;
}
void ChainedHashTable::withdraw(HashObject obj)
{
	array[h(obj)].deleteEl(obj.getrecord());
	this->numOfElements--;
}
HashObject ChainedHashTable::find(int KEY)
{
	HashObject *tmp = array[KEY].gethead();
	while (tmp != NULL && tmp->getkey() != KEY)
		tmp = tmp->getnext();
	if (tmp != NULL)
		return *tmp;
	else
	{
		throw "Nema objekta sa takvim kljucem u tablici.";
	}
}
void ChainedHashTable::display()
{
	for (int i = 0; i<this->length; i++)
	{
		cout << "[" << i << "]" << "-> ";
		HashObject *tmp = array[i].gethead();
		while (tmp)
		{
			tmp->print();
			tmp = tmp->getnext();
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
#include"HashTable.h"
#include<cmath>
HashTable::HashTable(int l)
{
	count = 0;
	length = l;
	niz = new SLList[l];
}
HashTable::~HashTable() { delete[] niz; }
int HashTable::h(HashObject obj)
{
	return(f(obj.getKey()) % length);
}
int HashTable::f(int a)
{
	return abs(a);
}
void HashTable::insert(HashObject obj)
{
	int probe = h(obj);
	niz[probe].addToHead(obj);
	count++;
}
HashObject* HashTable::find(HashObject obj)
{
	if (count == 0)
		throw "Tabela je prazna.";
	int probe = f(obj.getKey()) % length;
	HashObject* tmp;
	tmp = niz[probe].getHead();
	while (tmp)
	{
		if (tmp->operator==(obj))
			return tmp;
		tmp = niz[probe].head->next;
	}
	throw"Trazeni element ne postoji.";
}
void HashTable::printAll()
{
	if (count == 0)
		throw "Tabela je prazna";
	for (int i = 0;i < length;i++)
	{
		cout << "[" << i << "]" << " " << "->" << " ";
		HashObject* tmp = niz[i].getHead();
		while (tmp!=NULL)
		{
			tmp->print();
			cout << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}
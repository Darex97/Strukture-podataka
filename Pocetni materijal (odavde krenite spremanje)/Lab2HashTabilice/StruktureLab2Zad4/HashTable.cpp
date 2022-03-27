#include"HashTable.h"
HashTable::HashTable()
{
	broj = duzina = 0;
	niz = NULL;
}
HashTable::HashTable(int l)
{
	broj = 0;
	duzina = l;
	niz = new SLList[l];
}
HashTable::~HashTable()
{
	delete[] niz;
}
int HashTable::h(HashObject obj)
{
	return (f(obj.getKey()) % duzina);
}
void HashTable::insert(HashObject obj)
{
	int probe = h(obj);
	//if (niz[probe].head == NULL)
	{
		niz[probe].addToHead(obj);
	}
	//else
}
void HashTable::printAll()
{
	HashObject* tmp;
	for (int i = 0;i < duzina;i++)
	{
		cout << "[" << i << "]" << " " << "->" << " ";
		tmp = niz[i].head;
		while (tmp)
		{
			tmp->print();
			tmp = tmp->next;
		}
		cout << endl;
	}
}
/*
void HashTable::withdraw(int k)
{
	if (broj == 0)
		throw "Tabela je prazna.";
	int probe = f(k) % duzina;
	HashObject *novajlija = findMatch(k);
	if (novajlija == niz[probe].getHead())
		niz[probe].head = NULL;
	else
	{
		while (!(niz[probe].getNext()->isEqualKey(k)))
		{
			niz[probe].
		}
	}

}*/

HashObject* HashTable::findMatch(int k)
{

	int probe = f(k) % duzina;
	HashObject* pomocnik = niz[probe].getHead();
	while (!(pomocnik->isEqualKey(k)))
	{
		pomocnik = niz[probe].getNext();
	}
	return pomocnik;
}
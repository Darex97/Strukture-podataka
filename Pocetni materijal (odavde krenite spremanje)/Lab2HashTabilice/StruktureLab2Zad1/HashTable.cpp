#include"HashTable.h"

HashTable::HashTable()
{
	broj = 0;
	duzina = 0;
	niz = NULL;
}
HashTable::HashTable(int d)
{
	broj = 0;
	duzina = d;
	niz = new SLList[d];
}
HashTable::~HashTable() { delete[] niz; }

int HashTable::f(char* s)
{
	int result = 0;
	int a = 7;
	for (int i = 0;s[i] != '\0';i++)
	{
		result = result << a^s[i];
	}
	return result;
}
int HashTable::h(HashObject obj)
{
	return (f(obj.getKey()) % duzina);
}
void HashTable::insert(HashObject obj)
{
	int hash = h(obj);
	niz[hash].addToHead(obj);
	broj++;
}
HashObject* HashTable::find(char* s) 
{
	if (broj == 0)
		throw "Tabela je prazna.";

	int probe = f(s)%duzina;
	HashObject *tmp = niz[probe].head;
	while (tmp != NULL) 
	{
		if (tmp->isEqualKey(s))
			return tmp;
		tmp = tmp->next;
	}
	throw "U tabeli nema trazenog elementa";
}
HashObject* HashTable::find(HashObject obj)
{
	if (broj == 0)
		throw "Tabela je prazna.";
	int probe = f(obj.getKey()) % duzina;
	HashObject *tmp = niz[probe].head;
	while (tmp != NULL)
	{
		if (tmp==(niz[probe].head))
			return tmp;
		tmp = tmp->next;
	}
	throw "U tabeli nema trazenog elementa";


}
void HashTable::printAll()
{
	HashObject* tmp;
	for (int i = 0;i < duzina;i++)
	{
		cout << "[" << i << "]" << "->" << " ";
		tmp = niz[i].head;
		while (tmp != NULL)
		{
			tmp->print();
			tmp = tmp->next;
		}
		cout << endl;
	}
}

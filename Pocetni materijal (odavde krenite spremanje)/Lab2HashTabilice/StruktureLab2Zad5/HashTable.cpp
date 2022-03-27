#include"HashTable.h"

HashTable::HashTable() 
{
	this->count = 0;
	this->length = 0;
	
}
HashTable::HashTable(int l)
{
	count =0;
	length = l;
	this->niz = new HashObject[l+(int)(l*0.5)];
	lrmp = length;
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
	return(f(obj.getKey()) % length);
}

void HashTable::insert(HashObject obj)
{
	if (count == length)
		throw "The table is full!";
	long probe = h(obj);
	if (niz[probe].free)
	{
		
		niz[probe] = obj;
	}
	else
		insertSinonim(obj);
	count++;
}
void HashTable::insertSinonim(HashObject obj)
{
	int k = h(obj);
	while (niz[k].next != -1)
		k = niz[k].next;
	niz[k].next = lrmp;
	niz[lrmp] = obj;
	lrmp++;
	
}

int HashTable::find(HashObject obj)
{
	int k = h(obj.key);
	while (niz[k].key != obj.key)
		k = niz[k].next;

	return k;
};

void HashTable::printAll() 
{
	if (count == 0)
		throw "Hes tablica je prazna.";
	for (int i = 0;i < (length+0.5*length);i++) 
	{
		cout << "[" << i << "]" << "->" << " ";
		if (niz[i].getKey() != NULL)
		{
			niz[i].print();
		}
		else
			cout << "Ovo mesto je prazno.";
		cout << endl;
	}
}
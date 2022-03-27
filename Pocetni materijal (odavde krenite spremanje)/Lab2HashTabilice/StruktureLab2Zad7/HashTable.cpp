#include"HashTable.h"
#include"HashObject.h"
HashTable::HashTable()
{
	count = 0;
	length = 0;
	//niz = NULL;
}
HashTable::HashTable(int l)
{
	length = l;
	count = 0;
	this->niz = new HashObject[this->length];
}
HashTable::~HashTable() 
{
	if (count > 0)
	{
		for (int i = 0;i < length;i++)
		{
			if (niz[i].isFree())
			{
				niz[i].deleteRecord();
			}
		}
		delete[] niz;
	}
}
int HashTable::f(char* s)
{
	int result = 0;
	int a = 7;
	for (int i = 0;i < strlen(s);i++)
	{
		result = result << a^s[i];
	}
	return result;
}
int HashTable::h(HashObject obj)
{
	return (f(obj.getKey()) % length);
}
int HashTable::g(int a)
{
	//a je rezultat hes funkcije u prvom prolazu
	for (int i = 0;i < length;i++)
	{
		int vracam = (a + 3 * i) % length;
		//da si imao kvadratno trazenje bilo bi:
		//vracam=(a+K*i^2);
		//pri cemu je K proizvoljna celobrojna konstanta
		if (niz[vracam].isFree())
			return vracam;
	}
}
void HashTable::insert(HashObject obj)
{
	if (count == length)
		throw "Tablica je puna.";
	int offset = findUnoccupied(obj);
	niz[offset] = obj;
	niz[offset].free = false;
	count++;
}
int HashTable::findUnoccupied(HashObject obj)
{
	int hash = h(obj);
	int probe = hash;
	if (niz[hash].isFree())
	{
		return hash;
	}
	do 
	{
		probe = g(probe);
		if (niz[probe].isFree())
		{
			return probe;
		}
	} while (probe != hash);
	throw "Hes tablica je puna.";
}
int HashTable::findMatch(char* k)
{
	int probe = f(k) % length;
	if (niz[probe].isFree())
	{
		throw "Ne postoji trazeni element.";
	}
	else
	{
		if (niz[probe].isEqualKey(k))
		{
			return probe;
		}
		probe = g(probe);//ako ga nismo nasli idemo na
		//sinonim
	}
	throw "Ne postoji trazeni element.";
}
void HashTable::withdraw(char* s)
{
	if (count == 0)
		throw "Tabela je prazna.";

	int probe = findMatch(s);
	//array[probe].free = true;
	niz[probe].deleteRecord();
	count--;
}
void HashTable::printAll()
{
	if (count == 0)
		throw "Tablica je prazna.";
	for (int i = 0;i < length;i++)
	{
	
		{
			cout << "[" << i << "]" << " " << "->" << " ";
			if (!(niz[i].isFree()))//ako je zazuzet znaci
				//ima elemenata, treba da istampas
			{
				niz[i].print();
			}
			else//ako je slobodan nema sta da stampa
			{
				cout << "Trenutno nema elemenata.";
			}
			cout << endl;
		}
	}


}
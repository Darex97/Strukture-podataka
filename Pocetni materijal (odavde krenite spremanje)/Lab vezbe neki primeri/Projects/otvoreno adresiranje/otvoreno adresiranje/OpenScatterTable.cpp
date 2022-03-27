#include "OpenScatterTable.h"

OpenScatterTable::OpenScatterTable(int x)
{
	n = x;
	t = 0;
	a = new HashObject[n];
}
OpenScatterTable::~OpenScatterTable()
{
	if (t>0)
	{
		for (int i = 0; i<n; i++)
			if (!a[i].get_free())
				a[i].deleterecord();
		delete[] a;
	}
}
int OpenScatterTable::f(char* b)
{
	int res = 0;
	int a = 7;
	for (int i = 0; b[i] != 0; i++)
		res = res << a^b[i];
	return res;
}
int OpenScatterTable::h(HashObject obj)
{
	return (f(obj.get_keyword()) % n);
}
int OpenScatterTable::findunocupied(HashObject obj)//sekundarna f-ja
{
	int hash = h(obj);
	int probe = hash;
	do
	{
		probe = (probe + 1) % n;
		if (a[probe].get_free())
			return probe;
	} while (probe != hash);
	throw "Tablica je puna.";
}
int OpenScatterTable::findmatch(char* key)//sekundarna f-ja
{
	int probe = f(key) % n;
	for (int i = 0; i<n; i++)
	{
		probe = (probe + 1) % n;
		if (a[probe].get_free())
			return -1;
		if (!strcmp(a[probe].get_keyword(), key))
			return probe;
	}
	return -1;
}
void OpenScatterTable::insert(HashObject& obj)
{
	if (t == n)
		throw "Tablica puna";
	int offset = this->findunocupied(obj);
	a[offset] = obj;
	t++;
}
void OpenScatterTable::withdraw(char* key)
{
	if (t == 0)
		throw "Tablica prazna.";
	int offset = findmatch(key);
	if (offset<0)
		throw "Objekat ne postoji.";
	a[offset].deleterecord();
	t--;
}
void OpenScatterTable::display()
{
	for (int i = 0; i<n; i++)
		if (!a[i].get_free())
		{
			cout << "[" << i << "]" << "->";
			a[i].print();
		}
		else
			cout << "[" << i << "]" << endl;
	cout << "//////////" << endl;
}
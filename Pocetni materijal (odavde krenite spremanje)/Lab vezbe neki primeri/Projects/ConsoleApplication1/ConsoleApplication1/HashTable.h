#pragma once
#include "HashObject.h"

class HashTable
{
public:
	int n;
	int m;
	int noElem;
	HashObject *array;

	HashTable(int x)
	{
		m = x;
		n = 2 * m;
		array = new HashObject[n];
	}
	~HashTable()
	{
		if (noElem > 0)
			for (int i = 0; i < noElem; i++)
				if (!free)
					array[i].deleteRecord();
		delete[] array;
	}
	int f(char* s)
	{
		int res = 0;
		int a = 7;
		for (int i = 0; s[i] != 0; i++)
			res = res << a^s[i];
		return res;
	}
	int h(HashObject obj)
	{
		return (f(obj.getKey()) % m);
	}
	void display()
	{
		for (int i = 0; i < n; i++)
			if (!array[i].free)
			{
				cout << "[" << i << "]" << "->";
				array[i].print();
				cout << "|" << array[i].next << endl;
			}
			else
				cout << "[" << i << "]" << endl;
	}
	void insert(HashObject obj)
	{
		if (noElem == n - 1)
			throw "Tablica puna.";
		int probe1 = h(obj);
		int probe = m;
		if (!array[probe1].free)
		{
			while (array[probe].getNext() != -1)
				probe = array[probe].getNext();
			int tail = probe;
			probe = (probe + 1) % n;
			if (probe == n)
				probe = m;
			while (!array[probe].free && probe != tail)
				probe = (m + 1) % n;
			if (probe == tail)
				throw "Lose si izveo ponovno ulancavanje.";
			array[probe1].setNext(probe);
			array[probe] = obj;
			array[probe].setNext(-1);
			noElem++;
		}
		else
		{
			array[probe1] = obj;
			array[probe1].setNext(-1);
			noElem++;
		}
	}
	void withdraw(char* key)
	{
		if (noElem == 0)
			throw "Tabla je prazna";
		int probe = f(key) % m;
		int prev = -1;
		while (probe != -1 && strcmp(array[probe].getKey(), key))
		{
			prev = probe;
			probe = array[probe].getNext();
		}
		if (probe == -1)
			throw "Element nije nadjen.";
		if (prev != -1)
		{
			array[prev].setNext(array[probe].getNext());
			array[probe].deleteRecord();
		}
		else
		{
			if (array[probe].getNext() == -1)
			{
				array[probe].deleteRecord();
			}
			else
			{
				int nextel = array[probe].getNext();
				array[probe].deleteRecord();
				array[probe] = array[nextel];
				array[nextel].deleteRecord();
				array[nextel].setNext(-1);
			}
		}
		noElem--;
	}
};

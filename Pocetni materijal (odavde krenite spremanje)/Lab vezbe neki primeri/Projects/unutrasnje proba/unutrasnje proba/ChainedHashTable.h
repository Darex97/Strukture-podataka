#pragma once
#include "HashObject.h"

class ChainedHashTable
{
public:
	HashObject* array;
	int length;
	int noElem;

	ChainedHashTable(int len)
	{
		length = len;
		noElem = 0;
		array = new HashObject[length];
	}
	~ChainedHashTable()
	{
		for (int i = 0; i < length; i++)
			array[i].deleteRecord();
		delete [] array;
	}
	int h(HashObject obj)
	{
		char* tmp = obj.tel;
		int n = strlen(tmp);
		int br = 0;
		for (int i = n - 3; i<n; i++)
			br = br * 10 + (tmp[i] - '0');
		return br % 1000;
	}
	void insert(HashObject obj)
	{
		if (noElem == length)
			throw "Tablica je puna!";
		int kljuc = h(obj);
		if (!array[kljuc].free)
		{
		while (array[kljuc].next != -1)
		{
			kljuc = array[kljuc].next;
		}
		int tail = kljuc;
		kljuc = (kljuc + 1) % length;
		while (!array[kljuc].free && kljuc != tail)
			kljuc = (kljuc + 1) % length;
		if (kljuc == tail)
			throw "Lose si izveo ponovno ulancavanje.";
		array[tail].setNext(kljuc);
		}
		array[kljuc] = obj;
		array[kljuc].free = false;
		array[kljuc].setNext(-1);
		noElem++;
	}
	void withdraw(char* key)
	{
		if (noElem == 0)
			throw "Tabla je prazna";
		HashObject tmp("", "", key);
		int probe = h(tmp);
		int prev = -1;
		while (probe != -1 && strcmp(array[probe].tel, key))
		{
			prev = probe;
			probe = array[probe].next;
		}
		if (probe == -1)
			throw "Element nije nadjen.";
		if (prev != -1)
		{
			array[prev].setNext(array[probe].next);
			array[probe].deleteRecord();
		}
		else
		{
			if (array[probe].next == -1)
			{
				array[probe].deleteRecord();
			}
			else
			{
				int nextel = array[probe].next;
				array[probe].deleteRecord();
				array[probe] = array[nextel];
				array[nextel].deleteRecord();
				//array[nextel].setNext(-1);
			}
		}
		noElem--;
	}
	void display()
	{
		for (int i = 0; i < length; i++)
			if (!array[i].free)
			{
				cout << "[" << i << "]" << "->";
				array[i].print();
				cout << " next->" << array[i].next << endl;
			}

	}
};
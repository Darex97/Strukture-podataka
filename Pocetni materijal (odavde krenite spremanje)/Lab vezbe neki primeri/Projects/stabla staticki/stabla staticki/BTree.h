#pragma once
#include <iostream>
using namespace std;

class BTree
{
public:
	int *array;
	int duzina;
	int noElem;

	BTree()
	{
		duzina = 0;
		array = NULL;
		noElem = 0;
	}
	BTree(int duzina)
	{
		this->duzina = duzina;
		array = new int[duzina + 1];
		noElem = 0;
		for (int i = 0; i < duzina; i++)
		{
			array[i] = -1;
		}
	}
	~BTree()
	{
		delete[] array;
	}
	void insert(int el)
	{
		if (this->noElem == this->duzina)
			throw "Stablo je popunjeno.";
		int i = 0;
		while (i < duzina && array[i] != -1)
		{
			if (el < array[i])
				i = 2 * i + 1;
			else
				i = 2 * i + 2;
		}
		array[i] = el;
		noElem++;
	}

	bool isEmpty()
	{
		return noElem == 0;
	}

	void visit()
	{
		for (int i = 0; i < duzina; i++)
			cout << array[i] << " ";
	}
};
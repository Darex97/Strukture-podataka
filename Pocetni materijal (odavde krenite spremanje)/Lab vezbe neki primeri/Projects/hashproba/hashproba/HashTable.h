#pragma once
#include "LList.h"
class HashTable
{
public:
	int length;
	int noElem;
	LList* array;

	HashTable(int lenght)
	{
		this->length = lenght;
		noElem = 0;
		array = new LList[lenght];
	}
	int f(char* s)
	{
		int res = 0;
		int a = 7;
		for (int i = 0; s[i] != 0; i++)
			res = res << a ^ s[i];
		return res;
	}
	int h(HashObject obj)
	{
		return (f(obj.key) % length);
	}
	void insert(HashObject obj)
	{
		array[h(obj)].AddToHead(obj.key);
		noElem++;
	}
	void withdraw(HashObject obj)
	{
		array[h(obj)].deleteEl(obj.key);
		noElem--;
	}
	void display()
	{
		for (int i = 0; i<this->length; i++)
		{
			cout << "[" << i << "]" << "-> ";
			HashObject* tmp = array[i].getHead();
			while (tmp)
			{
				tmp->print();
				tmp = tmp->next;
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
	double FP()
	{
		 double a = (double)noElem / (double)length;
		 return a;
	}
};
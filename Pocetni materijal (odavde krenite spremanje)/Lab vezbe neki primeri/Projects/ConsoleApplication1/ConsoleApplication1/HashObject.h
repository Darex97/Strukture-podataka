#pragma once
#include <iostream>
using namespace std;

class HashObject
{
public:
	char* key;
	int next;
	bool free;

	HashObject()
	{
		key = NULL;
		next = -1;
		free = true;
	}
	HashObject(char* s)
	{
		key = s;
		next = -1;
		free = false;
	}
	HashObject(char *s, int n)
	{
		key = s;
		next = n;
		free = false;
	}

	HashObject& operator = (HashObject& obj)
	{
		if (this != &obj)
		{
			if (!this->free)
				delete[] key;
			this->key = obj.key;
			this->free = false;
			this->next = obj.getNext();
		}
		return*this;
	}
	int getNext()
	{
		return next;
	}
	char* getKey()
	{
		return key;
	}
	void setNext(int x)
	{
		next = x;
	}
	void deleteRecord()
	{
		if (!free)
		key = NULL;
		next = -1;
		free = true;
	}
	void print()
	{
		cout << key;
	}
};
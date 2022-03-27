#pragma once
#include <iostream>
using namespace std;

class HashObject
{
public:
	char* key;
	HashObject* next;
public:
	HashObject()
	{
		key = NULL;
		next = NULL;
	}
	
	HashObject(char *record)
	{
		next = NULL;
		key = record;
	}
	HashObject(char* k, HashObject* obj)
	{
		key = k;
		next = obj;
	}
	HashObject& operator = (HashObject& obj)
	{
		key = obj.key;
		next = obj.next;
	}
	bool operator == (HashObject& obj)
	{
		return key == obj.key;
	}
	
	char* getKey()
	{
		return key;
	}
	void print()
	{
		cout << getKey();
	}
};
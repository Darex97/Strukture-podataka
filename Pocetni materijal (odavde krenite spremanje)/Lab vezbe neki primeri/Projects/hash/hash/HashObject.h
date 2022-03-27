#pragma once
#include<iostream>
#include<string>
using namespace std;


class HashObject
{
public:
	int key;
	char *record;
	HashObject *next;

public:

	HashObject();
	HashObject(char*);
	HashObject(int, char*);
	HashObject(int x, char*, HashObject*);
	HashObject& operator=(const HashObject& obj);
	bool operator==(const HashObject& o);
	void deleterecord();
	int getkey();
	char* getrecord()
	{
		return record;
	};
	bool IsEqualKey(int k)
	{
		return this->key == k;
	};
	void print();
	void setnext(HashObject* sl)
	{
		this->next = sl;
	};
	HashObject* getnext()
	{
		return this->next;
	};
	~HashObject()
	{
		this->deleterecord();
	}
};


#pragma once
#include<iostream>
using namespace std;

class HashObject
{
public:
	long key;
	char *record;
	HashObject *synonym;

	HashObject(long phoneNum,char *subscriber);
	HashObject(long phoneNum,char* subscriber,HashObject *synonym);
	long getKey();
	char* getRecord();
	void print();
	~HashObject(void);
};


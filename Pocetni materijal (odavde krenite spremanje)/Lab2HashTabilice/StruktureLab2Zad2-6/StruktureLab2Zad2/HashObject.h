#pragma once
#include<iostream>
using namespace std;
class HashObject 
{
public:
	int key;
	char* record;
	HashObject* next;
public:
	HashObject();
	HashObject(int);
	HashObject(int, char*);
	HashObject(int, char*, HashObject*);
	~HashObject();

	HashObject operator=(HashObject);
	bool operator==(HashObject obj) { return (getKey() == obj.getKey() && getRecord() == obj.getRecord()); }
	int getKey() { return this->key; }
	char* getRecord() { return this->record; }
	void print();

};
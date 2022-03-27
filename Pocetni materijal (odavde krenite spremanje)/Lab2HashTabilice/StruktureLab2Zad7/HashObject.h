#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class HashObject {
public:
	char* key;
	bool free;
public:
	HashObject();
	HashObject(char* newKey);
	~HashObject();
	HashObject& operator=(HashObject& obj);
	bool operator==(HashObject& obj);
	void deleteRecord();
	char* getKey() { return key; }
	bool isFree() { return this->free; }
	bool isEqualKey(char* s) { return !(strcmp(key, s)); }
	void print();
};
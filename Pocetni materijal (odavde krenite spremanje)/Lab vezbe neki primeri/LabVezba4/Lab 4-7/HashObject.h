#pragma once
#include "string.h"
#include <iostream>

using namespace std;

class HashObject
{
public:
	char* record;
	char* key;
	int status;
public:
	HashObject(void);
	HashObject(char* key, char* record);
	HashObject(HashObject& obj);
	HashObject& operator=(HashObject& obj);
	~HashObject();

	char* getKey() { return key; }
	char* getRecord() { return record; }
	int getStatus() { return status; }
	
	void setKey(char* key) { this->key = key; }
	void setRecord(char* record) { this->record = record; }
	void setStatus(int status) { this->status = status; }
	
	void deleteRecord();
	void print();
};
#pragma once
#include <iostream>
#include "HashObject.h"
#include "string.h"

using namespace std;

class HashTable
{
private:
	HashObject* array;
	int length;
	int count;
public:
	HashTable(void);
	HashTable(int length);
	~HashTable(void);
	void insert(HashObject& obj);
	void withdraw(HashObject& obj);
	void withdraw(char* key);
	
	HashObject& find(char* key);

	int hash(char* key);
	int secHash(int index);

	int findUnoccupied(HashObject& obj);
	int findMatch(char* key);

	void printTable();
};
#pragma once
#include"SLList.h"
class HashTable 
{
public:
	int broj;
	int duzina;
	SLList* niz;
public:
	HashTable();
	HashTable(int);
	~HashTable();

	int f(char*);
	int h(HashObject);
	void insert(HashObject);
	HashObject* find(char*);
	HashObject* find(HashObject);

	void printAll();

	

};
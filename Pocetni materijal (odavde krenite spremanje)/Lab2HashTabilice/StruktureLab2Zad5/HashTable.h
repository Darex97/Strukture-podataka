#pragma once
#include"HashObject.h"
class HashTable 
{
public:
	int count;
	int length;
	HashObject* niz;
	int lrmp;
	
public:
	HashTable();
	HashTable(int);
	~HashTable();

	int f(char*);
	int h(HashObject obj);

	void insert(HashObject);
	void insertSinonim(HashObject);
	int find(HashObject);
	void printAll();
};
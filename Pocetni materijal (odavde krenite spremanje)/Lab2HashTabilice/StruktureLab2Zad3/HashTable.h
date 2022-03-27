#pragma once
#include"HashObject.h"
class HashTable 
{
public:
	int count;
	int length;
	HashObject* niz;
	HashObject* nizSinonima;
	int brojacSinonima;
public:
	HashTable();
	HashTable(int);
	~HashTable();

	int f(char*);
	int h(HashObject obj);
//	int g(int);

	void insert(HashObject);
	void insertSinonims();
	//HashObject findMatch(char*);
	
	void withdraw(char*);
	void pritAll();
};
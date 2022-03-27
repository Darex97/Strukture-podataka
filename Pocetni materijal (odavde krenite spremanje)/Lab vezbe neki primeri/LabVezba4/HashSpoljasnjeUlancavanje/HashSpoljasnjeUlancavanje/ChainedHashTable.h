#pragma once
#include"SLList.h"
class ChainedHashTable
{
public:
	SLList *array;
	int length;
	int count;

	ChainedHashTable(int length);
	void insert(HashObject obj);
	int h(HashObject obj);
	int f(int);
	int f(char*);
	void display();
	~ChainedHashTable(void);
};


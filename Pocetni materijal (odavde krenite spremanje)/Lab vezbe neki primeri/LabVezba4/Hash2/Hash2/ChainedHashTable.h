#pragma once
#include"SLList.h"
#include<cmath>

class ChainedHashTable
{
public:
	SLList *array;
	int length;
	int count;

	ChainedHashTable(int length);
	void insert(HashObject obj);
	int h(HashObject obj);
	void display();
	~ChainedHashTable(void);
};


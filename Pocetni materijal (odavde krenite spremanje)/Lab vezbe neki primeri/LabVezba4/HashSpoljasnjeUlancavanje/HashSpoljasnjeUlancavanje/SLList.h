#pragma once
#include"HashObject.h"

class SLList
{
public:
	HashObject *head;

	SLList();
	void addToHead(int key,char *word);
	~SLList();
};


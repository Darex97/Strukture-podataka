#pragma once
#include"HashObject.h"
class SLList
{
public:
	HashObject *head;

	SLList();
	void addToHead(long phoneNum,char* subscriber);
	~SLList(void);
};


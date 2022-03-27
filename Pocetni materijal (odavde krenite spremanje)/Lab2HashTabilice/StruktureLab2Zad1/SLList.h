#pragma once
#include "HashObject.h"
class SLList 
{
public:
	HashObject* head;
public:
	SLList();
	void addToHead(HashObject obj);
	~SLList();
};
#pragma once
#include"HashObject.h"
class SLList 
{
public:
	HashObject* head;
	
	SLList();
	void addToHead(HashObject);
	HashObject* getHead() { return head; }
	HashObject* getNext() { return head->next; }
	~SLList();
};
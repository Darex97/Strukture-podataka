#include"HashObject.h"
class SLList 
{
public:
	HashObject* head;
public:
	SLList();
	~SLList();
	void addToHead(HashObject);
	HashObject* getHead();

};
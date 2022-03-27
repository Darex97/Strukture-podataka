#include "SLList.h"
SLList::SLList()
{
	head = NULL;
}
SLList::~SLList() {}
void SLList::addToHead(HashObject obj)
{
	head = new HashObject(obj.getKey(), obj.getRecord(), head);
}
HashObject* SLList::getHead() 
{
	return head;
}

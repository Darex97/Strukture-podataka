#include "SLList.h"


SLList::SLList(void)
{
	this->head=NULL;
}
void SLList::addToHead(long key,char* subscriber)
{
	this->head=new HashObject(key,subscriber,this->head);
}
SLList::~SLList(void)
{
}

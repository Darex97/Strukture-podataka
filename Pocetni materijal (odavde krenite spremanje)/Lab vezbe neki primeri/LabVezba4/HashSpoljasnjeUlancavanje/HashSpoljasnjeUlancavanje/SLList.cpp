#include "SLList.h"


SLList::SLList()
{
	this->head=NULL;
}
void SLList::addToHead(int key,char *word)
{
	this->head=new HashObject(key,word,this->head);
}
SLList::~SLList(void)
{
}

#include"SLList.h"
SLList::SLList()
{
	head = NULL;
}
void SLList::addToHead(HashObject obj)
{
	head = new HashObject(obj.getKey(), obj.getRecord(), head);
}
SLList::~SLList() 
{

}
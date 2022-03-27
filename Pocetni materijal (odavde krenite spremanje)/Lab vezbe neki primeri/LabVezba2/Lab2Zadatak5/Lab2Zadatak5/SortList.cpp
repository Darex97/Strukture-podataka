#include "SortList.h"


CSortList::CSortList(void)
{
	this->head=NULL;
}
void CSortList::AddToHead(int number)
{
	this->head=new SLLNode(number,head);
}
void CSortList::Sort(bool up)
{
	if (up)
	{
		
	}
	else
	{

	}
}
CSortList::~CSortList(void)
{
}

#include "SLList.h"

SLList::SLList()
{
	head = NULL;
}
void SLList::addtohead(int x, char* s)
{
	head = new HashObject(x, s, head);
}
void SLList::deletefromhead()
{
	while (!IsEmpty())
	{
		HashObject *tmp = head;
		head = head->getnext();
		delete tmp;
	}
}
void SLList::deleteEl(char* zapis)
{
	HashObject* prev = NULL;
	HashObject* ptr = head;
	while (ptr != NULL && strcmp(ptr->getrecord(), zapis))
	{
		prev = ptr;
		ptr = ptr->getnext();
	}
	if (ptr != NULL)
	{
		if (ptr == head)
		{
			head = head->getnext();
			delete ptr;
		}
		else
			prev->setnext(ptr->getnext());
	}
	else
		throw "Nema elementa sa takvim kljucem u ovoj llisti.";
}

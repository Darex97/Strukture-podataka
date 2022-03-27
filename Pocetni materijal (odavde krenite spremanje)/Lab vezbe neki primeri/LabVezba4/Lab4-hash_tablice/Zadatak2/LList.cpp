#include "LList.h"

LList::LList()
{
	head=NULL;
}
void LList::addtohead(char* im,char* pr,char* tel)
{
	head=new HashObject(im,pr,tel,head);
}
void LList::deletefromhead()
{
	while(!IsEmpty())
	{
		HashObject *tmp=head;
		head=head->getnext();
		delete tmp;
	}
}
void LList::deleteEl(char* telefon)
{
	HashObject* prev=NULL;
	HashObject* ptr=head;
	while(ptr!=NULL && strcmp(ptr->gettel(),telefon))
	{
		prev=ptr;
		ptr=ptr->getnext();
	}
	if(ptr!=NULL)
	{
		if(ptr==head)
		{
			head=head->getnext();
			delete ptr;
		}
		else
		prev->setnext(ptr->getnext());
	}
	else
		cout<<"Nema elementa sa takvim kljucem u ovoj llisti."<<endl;
}
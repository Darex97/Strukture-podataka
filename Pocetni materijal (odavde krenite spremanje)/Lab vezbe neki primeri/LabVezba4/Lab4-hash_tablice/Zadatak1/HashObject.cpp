#include "HashObject.h"

HashObject::HashObject()
{
	this->record=NULL;
	this->key=-1;
	this->next=NULL;
}
HashObject::HashObject(char *c)
{
	this->record=c;
	this->key=-1;
	this->next=NULL;
}
HashObject::HashObject(int x,char *c)
{
	this->record=c;
	this->key=x;
	this->next=NULL;
}
HashObject::HashObject(int x,char* c,HashObject* sl)
{
	this->key=x;
	this->record=c;
		this->next=sl;
}
HashObject HashObject::operator=(HashObject obj)
{
	if(this!=&obj)
	{
		if(record!=NULL)
			delete [] record;
		record=obj.getrecord();
		key=obj.getkey();
		next=obj.getnext();
	}
	return *this;
}
void HashObject::deleterecord()
{
	if(record!=NULL)
	{
		delete [] record;
		record=NULL;
	}
}
void HashObject::print()
{
		cout<<this->getkey()<<" | "<<this->getrecord();
}

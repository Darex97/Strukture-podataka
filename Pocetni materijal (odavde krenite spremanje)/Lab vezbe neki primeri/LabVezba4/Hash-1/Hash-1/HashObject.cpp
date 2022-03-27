#include "HashObject.h"


HashObject::HashObject()
{
	this->key=-1;
	this->next=NULL;
	this->record=NULL;
}
HashObject::HashObject(char *record)
{
	this->key-1;
	this->next=NULL;
	this->record=record;
}
HashObject::HashObject(int key,char *record)
{
	this->key=key;
	this->next=NULL;
	this->record=record;
}
HashObject::HashObject(int key,char *record,HashObject *o)
{
	this->key=key;
	this->record=record;
	this->next=o;
}
HashObject& HashObject::operator=(const HashObject& obj)
{
	this->key=obj.key;
	this->next=obj.next;
	this->record=obj.record;

	return *this;
}
bool HashObject::operator==(const HashObject& obj)
{
	return this->record==obj.record;
}
void HashObject::deleterecord()
{
	if(this->record!=NULL)
	{
		delete []this->record;
		this->record=NULL;
	}
}
int HashObject::getkey()
{
	return this->key;
}
void HashObject::print()
{
		cout<<this->getkey()<<" | "<<this->getrecord();
}
//HashObject::~HashObject(void)
//{
//}

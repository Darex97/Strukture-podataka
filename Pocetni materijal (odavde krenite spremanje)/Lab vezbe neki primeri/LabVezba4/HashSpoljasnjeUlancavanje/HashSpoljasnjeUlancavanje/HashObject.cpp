#include "HashObject.h"


HashObject::HashObject(int key,char *word,HashObject *next)
{
	this->key=key;
	this->record=word;
	this->next=next;
}
HashObject::HashObject(int key,char *word)
{
	this->key=key;
	this->record=word;
	this->next=NULL;
}
int HashObject::getKey()
{
	return this->key;
}
char* HashObject::getRecord()
{
	return this->record;
}
void HashObject::print()
{
	cout<<this->getKey()<<"|"<<this->getRecord()<<" ";
}
HashObject::~HashObject(void)
{
}

#include"HashObject.h"
HashObject::HashObject()
{
	this->key = 0;
	record = NULL;
	next = NULL;
}
HashObject::HashObject(int br)
{
	this->key = br;
	record = NULL;
	next = NULL;
}
HashObject::HashObject(int br, char* ime)
{
	this->key = br;
	this->record = ime;
}
HashObject::HashObject(int br, char* ime, HashObject* obj)
{
	this->key = br;
	this->record = ime;
	next = obj;
}
HashObject HashObject::operator=(HashObject obj)
{
	this->key = obj.getKey();
	this->record = obj.getRecord();
	this->next = obj.next;
	return *this;
}
HashObject::~HashObject() {}

void HashObject::print() 
{
	cout << getKey() << "|" << getRecord() << " ";
}

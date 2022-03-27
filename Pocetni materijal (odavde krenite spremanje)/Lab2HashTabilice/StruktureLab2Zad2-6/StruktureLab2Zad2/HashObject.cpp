#include"HashObject.h"
HashObject::HashObject() 
{
	key = 0;
	record = NULL;
	next = NULL;
}
HashObject::HashObject(int br)
{
	key =  br;
	record = NULL;
	next = NULL;
}
HashObject::HashObject(int br, char* ime)
{
	key = br;
	record = ime;
	next = NULL;
}
HashObject::HashObject(int br, char* ime, HashObject* obj)
{
	key = br;
	record = ime;
	next = obj;
}
HashObject::~HashObject() {}
HashObject HashObject::operator=(HashObject obj)
{
	key = obj.key;
	record = obj.record;
	next = obj.next;
	return *this;
}
void HashObject::print() 
{
	cout << getKey() << "|" << getRecord() << " ";
}
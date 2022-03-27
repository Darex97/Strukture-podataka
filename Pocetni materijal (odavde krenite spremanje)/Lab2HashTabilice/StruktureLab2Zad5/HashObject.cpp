#include"HashObject.h"

HashObject::HashObject() { this->key = NULL;record = 0;free = true;next = -1; }
HashObject::HashObject(char* k) { this->key = k; record = 0;free = false; next = -1; }
HashObject::HashObject(char* k, int r) { this->key = k; record = r;free = false; next = -1; }
HashObject::HashObject(char* k,int r, int n) 
{
	this->key = k; 
	record = r;
	free = false; 
	next = n;
}
HashObject::HashObject(HashObject& obj)
{
	this->key = obj.getKey();
	this->record = obj.getRecord();
	this->next = obj.next;
	this->free = obj.free;
}
HashObject::~HashObject() { this->key = NULL;record = 0; free = true; }
HashObject& HashObject::operator=(HashObject obj)
{
	this->key = obj.getKey();
	this->free = obj.free;
	this->next = obj.next;
	this->record = obj.getRecord();
	return *this;
}
void HashObject::print()
{
	cout << this->getKey() << " | " <<getRecord()<<" | "<< this->next << " "; 
}

void HashObject::deleteRecord() 
{ 
	if (record)
	{
		record = 0;
		this->free = true;
		this->key = 0;
		this->next = NULL;
	}
}
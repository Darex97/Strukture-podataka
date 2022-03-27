#include "HashObject.h"

HashObject::HashObject()
{
	this->keyword = NULL;
	this->free = true;
}
HashObject::HashObject(char* rec)
{
	this->keyword = rec;
	this->free = false;
}
void HashObject::deleterecord()
{
	if (this->keyword != NULL)
	{
		keyword = NULL;
		this->free = true;
	}
}
void HashObject::print()
{
	cout << " " << keyword << " " << endl;
}
HashObject& HashObject::operator=(HashObject& b)
{
	if (this != &b)
	{
		if (!this->free)
			delete[] keyword;
		this->keyword = b.get_keyword();
		this->free = false;
	}
	return*this;
}
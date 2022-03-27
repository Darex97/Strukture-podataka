#include "HashObject.h"

HashObject::HashObject(void)
{
	key = 0;
	record = 0;
	status = 0;
}

HashObject::HashObject(char *key, char *record)
{
	this->key = key;
	this->record = record;
	status = 2;
}

HashObject::HashObject(HashObject& obj)
{
	key = obj.getKey();
	record = obj.getRecord();
}

HashObject& HashObject::operator=(HashObject& obj) {
	key = obj.getKey();
	record = obj.getRecord();

	return *this;
}

HashObject::~HashObject(void)
{
	deleteRecord();
}

void HashObject::deleteRecord()
{
	/*if (record)
		delete record;*/
}

void HashObject::print() {
	if (status == 2 && record)
		cout << record;
}
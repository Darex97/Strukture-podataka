#include "HashObject.h"
#include <iostream.h>

HashObject::HashObject()
{
	key = 0; 
	re rd = 0;
}
	
HashObject::HashObject(char * k)
{
	key = k; 
	record = 0;
}

	
HashObject::HashObject(char* k, long object)
{
	key = k; 
	record = object;
}
	
HashObject& HashObject::operator=(HashObject& obj)
{
	key = obj.key;
	record = obj.record;
	return *this;
}
	
bool HashObject::operator==(HashObject& obj)
{
	return record == obj.record;
}
	
void HashObject::Print()
{
	cout<<key<<"|"<<record<<endl;
}
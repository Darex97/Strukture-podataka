#include "HashObject.h"
#include <string.h>
#include <iostream.h>

HashObject::HashObject()
{
	key=new char[0];
	record=new char[0];
}

HashObject::~HashObject()
{
}


HashObject::HashObject(char* k,char* obj)
{
	record=new char[strlen(k)];
	strcpy(record,k);
	key=new char[strlen(obj)];
	strcpy(key,obj);
}

HashObject HashObject::operator=(HashObject obj)
{
	key=new char[strlen(obj.key)];
	record=new char[strlen(obj.record)];
	strcpy(record,obj.record);
	strcpy(key,obj.key);
	return *this;
}

char* HashObject::GetKey()
{
	return key;
}

void HashObject::Print()
{
	
	cout<<key<<"|"<<record;

}
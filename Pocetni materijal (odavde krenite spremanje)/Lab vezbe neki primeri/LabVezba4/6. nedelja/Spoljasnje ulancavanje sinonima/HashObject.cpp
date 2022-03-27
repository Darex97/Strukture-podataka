#include "HashObject.h"
#include <string.h>
#include <iostream.h>

HashObject::HashObject()
{
	key=new char[0];
	name=new char[0];
	number=new char[0];
}

HashObject::~HashObject()
{
}


HashObject::HashObject(char* na, char* nu)
{
	name=new char[strlen(na)];
	number=new char[strlen(nu)];
	strcpy(name,na);
	strcpy(number,nu);
	key=new char[strlen(name)];
	strcpy(key,name);
}


HashObject HashObject::operator=(HashObject obj)
{
	key=new char[strlen(obj.key)];
	name=new char[strlen(obj.name)];
	number=new char[strlen(obj.number)];
	strcpy(name,obj.name);
	strcpy(number,obj.number);
	strcpy(key,obj.key);
	return *this;
}

char* HashObject::GetKey()
{
	return key;
}

void HashObject::Print()
{
	cout<<name<<","<<number;
}
#include "HashObject.h"
#include <iostream.h>

HashObject::HashObject()
{
	key=0;
	recor NULL;
	next=-1;
	free=true;
}

HashObject::HashObject(char* k)
{
	key=k;
	record=NULL;
	next=-1;
	free=true;
}

HashObject::HashObject(char* k,char* object)
{
	key=k;
	record=object;
	next=-1;
	free=true;
}

HashObject::HashObject(char* k,char* object,unsigned int n)
{
	key=k;
	record=object;
	next=n;
	free=true;
}

void HashObject::DeleteRecord()
{
	if (record)
		record=NULL;
}

void HashObject::Print()
{
	cout<<key<<"|"<<record;
}
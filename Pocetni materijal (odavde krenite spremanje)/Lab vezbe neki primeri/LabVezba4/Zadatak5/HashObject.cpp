#include "HashObject.h"

HashObject::HashObject()
{
	this->keyword=NULL;
	this->next=-1;
	this->free=true;
}
HashObject::HashObject(char* rec)
{
	this->keyword=rec;
	this->free=false;
	this->next=-1;
}
HashObject::HashObject(char* rec,int sl)
{
	this->keyword=rec;
	this->next=sl;
	this->free=false;
}
void HashObject::deleterecord()
{
	if(this->keyword!=NULL)
	{
		keyword=NULL;
		this->free=true;
	}
}
void HashObject::print()
{
	cout<<" "<<keyword<<" ";
}
HashObject& HashObject::operator=(HashObject& b)
{
	if(this!=&b)
	{
		if(!this->free)
			delete [] keyword;
		this->keyword=b.get_keyword();
		this->free=false;
		this->next=b.get_next();
	}
	return*this;
}
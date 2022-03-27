#include "HashObject.h"

HashObject::HashObject()
{
	this->ime=NULL;
	this->prezime=NULL;
	this->tel=NULL;
	this->next=-1;
	this->free=true;
}
HashObject::HashObject(char* i,char* p,char* t)
{
	this->ime=i;
	this->prezime=p;
	this->tel=t;
	this->free=false;
	this->next=-1;
}
HashObject::HashObject(char* i,char* p,char* t,int sl)
{
	this->ime=i;
	this->prezime=p;
	this->tel=t;
	this->next=sl;
	this->free=false;
}
void HashObject::deleterecord()
{
	if(!this->free)
	{
	/*	delete  []keyword;*/
		ime=NULL;
		prezime=NULL;
		tel=NULL;
		this->free=true;
	}
}
void HashObject::print()
{
	cout<<ime<<" "<<prezime<<" "<<tel<<" ";
}
HashObject& HashObject::operator=(HashObject& b)
{
	if(this!=&b)
	{
		this->ime=b.get_ime();
		this->prezime=b.get_prezime();
		this->tel=b.get_tel();
		this->free=false;
		this->next=b.get_next();
	}
	return *this;
}
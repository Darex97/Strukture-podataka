#include "HashObject.h"

HashObject::HashObject()
{
	this->ime=NULL;
	this->prezime=NULL;
	this->tel=NULL;
	this->free=true;
}
HashObject::HashObject(char* i,char* p,char* t)
{
	this->ime=i;
	this->prezime=p;
	this->tel=t;
	this->free=false;
}
void HashObject::deleterecord()
{
	if(!this->free)
	{
		ime=NULL;
		prezime=NULL;
		tel=NULL;
		this->free=true;
	}
}
void HashObject::print()
{
	cout<<ime<<" "<<prezime<<" "<<tel<<" "<<endl;;
}
HashObject& HashObject::operator=(HashObject& b)
{
	if(this!=&b)
	{
		this->ime=b.get_ime();
		this->prezime=b.get_prezime();
		this->tel=b.get_tel();
		this->free=false;
	}
	return *this;
}
#include "HashObject.h"

HashObject::HashObject()
{
	this->ime=0;
	this->prezime=0;
	this->key=-1;
	this->tel=0;
	this->next=NULL;
}
HashObject::HashObject(char* im,char* pre,char* tl)
{
	this->ime=im;
	this->prezime=pre;
	this->tel=tl;
	this->next=NULL;
}
HashObject::HashObject(char* im,char* pre,char* tl,HashObject* sl)
{
	this->ime=im;
	this->prezime=pre;
	this->tel=tl;
	this->next=sl;
}
HashObject HashObject::operator=(HashObject b)
{
	if(this!=&b)
	{
		if(this->ime!=0)
			delete [] ime;
		if(this->prezime!=0)
			delete [] prezime;
		if(this->tel!=0)
			delete [] tel;
		this->ime=b.getime();
		this->prezime=b.getprezime();
		this->tel=b.gettel();
		this->next=b.getnext();//?
		this->key=b.getkey();
	}
	return *this;
}
void HashObject::deleteobj()
{
	if(this->ime!=0)
			delete [] ime;
		if(this->prezime!=0)
			delete [] prezime;
		if(this->tel!=0)
			delete [] tel;
}
void HashObject::print()
{
	cout<<this->ime<<" "<<this->prezime<<" "<<this->tel;
}
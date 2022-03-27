#include "HashObject.h"


HashObject::HashObject(long phoneNum,char *subscriber)
{
	this->key=phoneNum;
	this->record=subscriber;
	this->synonym=NULL;
}
HashObject::HashObject(long phoneNum,char *subscriber,HashObject *synonym)
{
	this->key=phoneNum;
	this->record=subscriber;
	this->synonym=synonym;
}
char* HashObject::getRecord()
{
	return this->record;
}
long HashObject::getKey()
{
	return this->key;
}
void HashObject::print()
{
	cout<<"Pretplatnik:"<<this->getRecord()<<"-"<<"011/"<<this->getKey()<<"|";
}
HashObject::~HashObject(void)
{
}

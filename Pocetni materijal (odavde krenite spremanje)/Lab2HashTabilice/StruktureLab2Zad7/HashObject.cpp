#include"HashObject.h"

HashObject::HashObject() {
	this->key = NULL;//ne mozemo da iskoristimo
	//strcpy jer key nije u statickoj zoni memorije
	//morali bismo prvo da zauzemo memoriju za njega
	// pa tek onda da upotrebimo fju
	free = true;
}
HashObject::HashObject(char* newKey)
{
	this->key = newKey;
	free = false;
}
HashObject::~HashObject()
{ 
	if (this->key != NULL)
	{
		key = NULL;
		this->free = true;
	}
}
HashObject& HashObject::operator=(HashObject& obj) 
{
	this->key = obj.key;
	this->free = obj.free;
	return *this;
}
bool HashObject:: operator==(HashObject& obj) 
{
	return isEqualKey(obj.key);
}
void HashObject::deleteRecord() { 
	key=NULL; 
	free = true; 
}
void HashObject::print() 
{
	cout << getKey() << " ";
}

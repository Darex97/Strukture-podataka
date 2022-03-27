#include"HashObject.h"
HashObject::HashObject() 
{
	key = NULL;
	record = 0;
	next = NULL;
}
HashObject::HashObject(char* k)
{
	/*When you say char * str1 in C, you are
	allocating a pointer in the memory. 
	When you write str1 = "Hello";
	you are creating a string literal in memory 
	and making the pointer point to it. 
	When you create another string literal 
	"new string" and assign it to str1, 
	all you are doing is changing where the 
	pointer points.*/
	key = k;
	record = 0;
	next = NULL;
}
HashObject::HashObject(char* k, int r)
{
	key = k;
	record = r;
	next = NULL;
}
HashObject::HashObject(char* k, int r, HashObject* obj)
{
	key = k;
	record = r;
	next = obj;
}
HashObject::~HashObject() 
{
	key = NULL;
	next = NULL;
	record = 0;
}
bool HashObject::operator==(HashObject* obj)
{
	return (obj->getKey() == key && obj->getRecord() == record);
}
void HashObject::print()
{
	cout << getKey() << "|" << getRecord() << " ";
}

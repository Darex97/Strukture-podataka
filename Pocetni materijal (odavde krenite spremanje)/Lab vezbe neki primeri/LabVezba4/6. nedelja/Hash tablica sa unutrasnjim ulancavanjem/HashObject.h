#include <string.h>

class HashObject
{
private:

	char* key;

	char* record;

public:

	b l free;

	long next;


	HashObject();
	HashObject(char* k);
	HashObject(char* k,char* object);
	HashObject(char* k,char* object,unsigned int n);


	void DeleteRecord();


	char* GetKey()
	{
		return key;
	}


	char* GetRecord()
	{
		return record;
	}


	bool IsEqualKey(char* k)
	{
		if (strcmp(key,k)==0)
			return true;
		else
			return false;
	}


	void Print();

};
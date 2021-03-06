#include "HashObject.h"
#include "Exception.h"

class HashTable
{
private:

	unsigned int length;
	uns
 ned int count;

	HashObject* array;

	unsigned int h(HashObject obj);
	
	unsigned int f(char* s);
	
	unsigned int g(unsigned int i);

public:


	HashTable(unsigned int len);

	~HashTable();

	void Display();

	void Insert(HashObject obj);

	HashObject Find(char* key);

	void Withdraw (char* key);


	unsigned int GetLength()
	{
		return this->length;
	}

	double GetLoadFactor()
	{
		return (double)count/(double)length;
	}
};
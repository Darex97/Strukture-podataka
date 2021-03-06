#include "SLList.h"
//#include "HashObject.h"

class HashTable
{
private:
	int length;
	int count;
	SL st *array;

	int h(HashObject obj);

	int f(char* s);

	//int g(int i);

public:

	int GetLength()
	{
		return length;
	}

	double GetLoadFactor()
	{
		return (double)count/(double)length;
	}


	HashTable(int l);
	~HashTable();

	void Insert(HashObject obj);

	void WithDraw(HashObject obj);

	void Print();

};
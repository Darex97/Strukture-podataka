//#include "HashObject.h"
#include "HashTable.h"

void main()
{
	HashTable t(10);
	t.Insert(HashObject("Danilo","0637267357"));
	
	t.Insert(HashObject("Maja","0637357"));
	t.Insert(HashObject("Aca","07357"));
	t. sert(HashObject("Da","07357"));
	t.Insert(HashObject("Mrko","0657"));

	t.Print();
}
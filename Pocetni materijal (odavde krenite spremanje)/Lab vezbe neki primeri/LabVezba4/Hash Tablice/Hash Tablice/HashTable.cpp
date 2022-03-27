#include "HashTable.h"

HashTable::HashTable(unsigned int len)
{
	lenght = len ;
	count = 0;
	/*za spoljasnje ulancavanje*/
	arrayS = new SortList [len];
 
}

void HashTable::InsertS(HashObject obj)
{
	arrayS[h(obj)].addToHead(obj);
	count++;
}
void HashTable::withDraw(HashObject obj)
{
	arrayS[h(obj)].deleteEl(obj);
	count--;
}

void HashTable::withDraw(int key)
{
	HashObject obj = find(key);
	withDraw(obj);
}

HashObject HashTable::find (int key)
{
	HashObject obj;
	unsigned int i = f(key)%lenght ;
	obj = arrayS[i].getHeadEl();
	while(!(obj.isEqualKey(key))) obj =arrayS[i].getHeadEl(obj);
	return obj;
}



HashTable::~HashTable(void)
{
	// destruktor za spoljasnje heshiranje
	HashObject obj;
	for(unsigned int i= 0 ; i< lenght; i++)
	{
		try{
			obj = arrayS[i].getHeadEl();
			while(true)
			{
				obj.deleteRecord();
				obj = arrayS[i].getHeadEl();
			}
		}
		catch(char *e){}
	}
	delete [] arrayS;
}

#include"HashTable.h"
void main() 
{
	try
	{
		HashTable Tablica(10);
		HashObject o1("for");
		HashObject o2("while");
		HashObject o3("do");
		HashObject o4("for");
		HashObject o5("array");
		Tablica.insert(o1);
		Tablica.insert(o2);
		Tablica.insert(o3);
		Tablica.insert(o4);
		Tablica.insert(o5);
		Tablica.printAll();
		cout << Tablica.findMatch("do") << endl;
		Tablica.withdraw("for");
		Tablica.printAll();
	}
	catch (char* izuzetak)
	{
		cout << izuzetak;
	}

}
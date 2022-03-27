#include "ChainedHashTable.h"

void main()
{
	try
	{
	ChainedHashTable a(1000);
	HashObject p("Marko", "Nikolic", "010/318-600");
	a.insert(p);
	HashObject p1("Pera", "Peric", "010/318-939");
	a.insert(p1);
	HashObject p2("Vladan", "Krstic", "010/318-011");
	a.insert(p2);
	HashObject p3("Jovana", "Markovic", "010/326-609");
	a.insert(p3);
	HashObject p4("Jovana", "Markovic", "010/326-609");
	a.insert(p4);
	a.display();
	cout << endl;
	a.withdraw("010/318-939");
	a.withdraw("010/326-609"); 
	a.display();
	}
	catch (char* s)
	{
		cout << s << endl;
	}
}
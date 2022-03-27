#include "HashTable.h"

void main()
{
	try
	{
		HashTable a(1000);
		HashObject p1("Pera","Peric","010/318-939");
		a.insert(p1);
		HashObject p2("Vladan","Krstic","010/318-011");
		a.insert(p2);
		HashObject p3("Jovana","Markovic","010/326-609");
		a.insert(p3);
		HashObject p4("Jovana","Markovic","010/326-609");
		a.insert(p4);
		HashObject p5("Pera","Peric","010/318-939");
		a.insert(p5);
		HashObject p6("Vladan","Krstic","010/318-011");
		a.insert(p6);
		a.display();
		a.withdraw("010/318-939");
		a.display();
	}
	catch(char *x)
	{
		cout<<x<<endl;
	}
}
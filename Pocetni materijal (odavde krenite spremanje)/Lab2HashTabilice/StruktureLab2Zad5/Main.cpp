#include"HashTable.h"
void main()
{
	try 
	{
		HashTable t(10);
		HashObject o1("for", 1);
		HashObject o2("while", 2);
		HashObject o3("for", 543);
		HashObject o4("do", 443);
		HashObject o5("for", 12);
		HashObject o6("array", 98);
		HashObject o7("matrix", 23);
		t.insert(o1);
		t.insert(o2);
		t.insert(o3);
		t.insert(o4);
		t.insert(o5);
		t.insert(o6);
		t.insert(o7);
		t.printAll();
		cout << endl << endl;

		cout << "Kljucna rec array se nalazi na poziciji sa indeksom: " << t.find("array") << endl;
		cout << endl;


		t.printAll();
	}
	catch (char* izuzetak)
	{
		cout << izuzetak;
	}
}
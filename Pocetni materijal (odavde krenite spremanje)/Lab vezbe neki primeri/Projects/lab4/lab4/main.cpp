#include "HashTable.h"

void main()
{
	try
	{
		HashTable a(10);
		HashObject o1("for");
		a.insert(o1);
		HashObject o2("while");
		a.insert(o2);
		HashObject o3("foreach");
		a.insert(o3);
		HashObject o4("float");
		a.insert(o4);
		HashObject o5("int");
		a.insert(o5);
		HashObject o6("switch");
		a.insert(o6);
		HashObject o7("case");
		a.insert(o7);
		a.display();//dobro rasipanje!!!
		a.withdraw("foreach");
		a.display();
	}
	catch (char* x)
	{
		cout << x << endl;
	}
}
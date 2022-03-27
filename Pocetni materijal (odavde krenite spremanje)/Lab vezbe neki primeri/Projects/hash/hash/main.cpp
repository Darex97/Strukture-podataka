#include "ChainedHashTable.h"
void main()
{
	try
	{
		ChainedHashTable a(10);
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
		HashObject o7("catch");
		a.insert(o7);
		a.display();
		a.withdraw(o4);
		a.display();
		

		HashObject b = a.find(0);
		b.print();
		cout << endl;

		//pokusavam iz praznog mesta da uzmem element
		b = a.find(9);

	}
	catch (char* message)
	{
		cout << message << endl;
	}
}
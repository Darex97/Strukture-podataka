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
		a.display();//dobro rasipanje!!!
		a.withdraw(o4);
		a.display();
	}
	catch(char* x)
	{
		cout<<x<<endl;
	}
}